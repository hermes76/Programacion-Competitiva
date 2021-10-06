
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



string solve()
{
    ll n;
    cin>>n;
    vector <ll> a;
    vector <ll> b;
    a.resize(n);
    b.resize(n);

    ll valor=0;

    for(ll x=0; x<n; x++)
        cin>>a[x];
    for(ll x=0; x<n; x++)
        cin>>b[x];


   ll x=0;
   while(x<n&&b[x]-a[x]==0)
    x++;

   if(x<n)
   {
       valor=b[x]-a[x];
       for(x; x<n && b[x]-a[x]==valor; x++)
       {
           if(b[x]-a[x]<0)
            return "NO";
       }
       for(x; x<n; x++)
            if(b[x]-a[x]!=0)
            return "NO";
   }
   return "YES";



}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}

