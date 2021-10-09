#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//typedef tree<pair<long long,long long>,null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007

typedef long long ll;
typedef double dll;


 bool comp( tuple<ll,ll,ll>a, tuple<ll,ll,ll> b)
{
    if(get<0>(a)<get<0>(b))
        return 1;
    else if( get<0>(a) == get<0>(b) && get<1>(a)>get<1>(b))
        return 1;
    return 0;

}
void solve()
{
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>> ranges;

    ordered_multiset contains;
    ordered_multiset contain_it;

    vector<ll> ans_1;
    vector<ll> ans_2;

    ans_1.resize(n);
    ans_2.resize(n);
    ranges.resize(n);


    for(ll x=0; x<n; x++)
    {
        cin>>get<0>(ranges[x])>>get<1>(ranges[x]);
        get<2>(ranges[x])=x;
    }

    sort(all(ranges),comp);

    for(ll x=n-1; x>=0; x--)
    {
        //upperbound
            ans_1[get<2>(ranges[x])]=contains.order_of_key(get<1>(ranges[x])+1);
        contains.insert(get<1>(ranges[x]));
    }

    for(ll x=0; x<n; x++)
    {
        //lowerbound
            ans_2[get<2>(ranges[x])]=contain_it.size()-contain_it.order_of_key(get<1>(ranges[x]));
        contain_it.insert(get<1>(ranges[x]));
    }
    for(auto x: ans_1)
        cout<<x<<" ";

    cout<<endl;

    for(auto x:ans_2)
        cout<<x<<" ";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
