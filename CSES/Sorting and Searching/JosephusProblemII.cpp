


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007

ll solve()
{
    ll n,m;
    ordered_set circle;
    cin>>n>>m;
    for(ll x=1; x<=n; x++)
        circle.insert(x);

    ll inicio=0;
    while(!circle.empty())
    {
        inicio%=circle.size();
        inicio=(inicio+m)%circle.size();
        auto t=circle.find_by_order(inicio);
        cout<<*t<<" ";
        circle.erase(t);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
