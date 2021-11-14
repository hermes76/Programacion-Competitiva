
//libraries
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//namespaces
//using namespace __gnu_pbds;
using namespace std;

//templates
/*
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

*/

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
    ll n;
    cin>>n;
    string cad;
    cin>>cad;
    vll minimos(26,INF);

    ll cont=0;
    for(ll x=0; x<26; x++)
    {
        cont=0;
        ll izq=0,der=cad.size()-1;
        while(izq<der)
        {
            if(cad[izq]=='a'+x && cad[der]!='a'+x){
                izq++;
                cont++;
            }
            else if(cad[izq]!='a'+x && cad[der]=='a'+x)
            {
                der--;
                cont++;
            }
            else if(cad[izq]==cad[der])
            {
                der--;
                izq++;
            }
            else if(cad[izq]!= cad[der])
            {
               cont=INF;
                break;
            }

        }
        minimos[x]=cont;
    }
    ll ans=INF;

    for(ll x=0; x<26; x++)
        ans=min(ans,minimos[x]);

    if(ans==INF)
        cout<<-1<<endl;
    else
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    //t=1;
    cin>>t;
    while(t--)
        solve();
}
