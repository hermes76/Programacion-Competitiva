//libraries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using namespace __gnu_pbds;
using namespace std;

//templates

template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;



//typedefs
typedef long long ll;
typedef double dll;
typedef vector<ll> vll;

//defines
#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007


void solve()
{
    ll n,k;
    cin>>n>>k;
    vll nums(n);
    set<pair<ll,ll>> L;
    set<pair<ll,ll>>R;
    ll sumL=0;
    ll sumR=0;

    for(ll x=0; x<n; x++)
        cin>>nums[x];
    if(k==1)
    {
        for(ll x=0;x <n; x++) cout<<"0 ";
        return;
    }
    if(k==2)
    {
        for(ll x=1; x<n; x++)
            cout<<max(nums[x-1],nums[x])-min(nums[x-1],nums[x])<<" ";
        return;
    }

    vector<pair<ll,ll>> sorted(k);

    for(ll x=0; x<k; x++)
        sorted[x]={nums[x],x};

    sort(all(sorted));

    for(ll x=0; x<=(k-1)/2; x++)
    {
        L.insert(sorted[x]);
        sumL+=sorted[x].first;
    }
    for(ll x=(k-1)/2+1; x<k; x++)
    {
        R.insert(sorted[x]);
        sumR+=sorted[x].first;
    }
    cout<<((L.rbegin())->first*L.size() -sumL)+ (sumR - L.rbegin()->first * R.size())<<" ";

    for(ll x=k; x<n; x++)
    {
        pair<ll,ll> current={nums[x],x};
        pair<ll,ll> past = {nums[x-k],x-k};

        if(past<=*L.rbegin())
        {
            sumL-=past.first;
            L.erase(past);
        }
        else
        {
            sumR-=past.first;
            R.erase(past);
        }
        if(current<*L.rbegin())
        {
            sumL+=current.first;
            L.insert(current);
        }
        else
        {
            sumR+=current.first;
            R.insert(current);
        }

        if(L.size()>(k-1)/2+1)
        {
           sumL-=L.rbegin()->first;
           sumR+=L.rbegin()->first;
           R.insert(*L.rbegin());
           L.erase(*L.rbegin());
        }
        if(L.size()<(k-1)/2+1)
        {
           sumL+=R.begin()->first;
           sumR-=R.begin()->first;
           L.insert(*R.begin());
           R.erase(*R.begin());
        }

         cout<<((L.rbegin())->first*L.size() -sumL)+ (sumR - L.rbegin()->first * R.size())<<" ";
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}

