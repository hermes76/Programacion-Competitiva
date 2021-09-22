
#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;*/

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double dll;

vector <ll> vll;
ll solveA(ll a,ll b,ll c,ll d,ll e,ll f)
{
    ll minimo=min(a,d);
        ll res=minimo*e;
    d-=minimo;
    res+=min(b,min(d,c))*f;
    return res;
}
ll solve()
{
    ll a,b,c,d;
    ll e,f;
    cin>>a>>b>>c>>d>>e>>f;
     ll maximo1=solveA(a,b,c,d,e,f);
     ll maximo2=0;
     maximo2+=min(b,min(c,d))*f;

     if(c==d)
     {
         c=0;
         d=0;
     }
     ll minimo=min(b,min(c,d));
     d-=minimo;
     maximo2+=min(a,d)*e;
     return max(maximo1,maximo2);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}

