
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

void solve()
{
    ll n;
    char a;
    cin>>n>>a;
    string cad;
    cin>>cad;

   vector <ll> ans;

   if(cad[n-1]==a)
   {
         for(ll x=0; x<n; x++)
            if(cad[x]!=a)
            {
                cout<<1<<endl<<n<<endl;
                return;
            }
        cout<<0<<endl;
       return;
   }
   if(cad[n-2]==a)
   {
       for(ll x=0; x<n; x++)
            if(cad[x]!=a)
            {
                cout<<1<<endl<<n-1<<endl;
                return;
            }
        cout<<0<<endl;
       return;
   }
   for(ll x=n-3; x>=n/2; x--)
        if(cad[x]==a)
        {
            cout<<1<<endl<<x+1<<endl;
            return;
        }
   cout<<2<<endl<<n-1<<" "<<n<<endl;




}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();
}

