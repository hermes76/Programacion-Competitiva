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
#define INF 1000000000000000000
#define MOD 1000000007

void solve()
{
   ll a,b,c;
   cin>>a>>b>>c;

   ll _a= b-(c-b);
   ll _c =a+(b-a)*2;
   ll _b= (c-a)/2;

   if(_a%a==0 && _a>=a)
    cout<<"YES";

   else if(_c%c==0 && _c>=c)
    cout<<"YES";

    else if((a+_b)%b==0 && a+_b>=b && (c-a)%2==0)
        cout<<"YES";
    else cout<<"NO";

    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    while(t--)
        solve();
}
