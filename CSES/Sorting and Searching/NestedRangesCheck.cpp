
#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;*/

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double dll;

bool comp(tuple<ll,ll,ll>a, tuple<ll,ll,ll> b)
{
    if(get<0>(a)<get<0>(b))
        return true;
    if( get<0>(a)== get<0>(b) && get<1>(a)>get<1>(b))
        return true;
    return false;
}

void solve()
{
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>> range;
    vector<bool> res_1;
    vector<bool> res_2;
    range.resize(n);
    res_1.resize(n,0);
    res_2.resize(n,0);

    for(ll x=0; x<n; x++)
    {
        cin>>get<0>(range[x])>>get<1>(range[x]);
        get<2>(range[x])=x;
    }
    sort(all(range),comp);


    ll mini=INF;
    ll maxi=-INF;
    for(ll x=0; x<n; x++)
    {
        if(maxi>= get<1>(range[x]))
        {
            res_2[get<2>(range[x])]=1;
        }
        maxi=max(maxi, get<1>(range[x]));
    }

     for(ll x=n-1; x>=0; x--)
    {
        if(mini<= get<1>(range[x]))
        {
            res_1[get<2>(range[x])]=1;
        }
        mini=min(mini, get<1>(range[x]));
    }

    for(auto i:res_1)
        cout<<i<<" ";
    cout<<endl;
      for(auto i:res_2)
        cout<<i<<" ";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

