
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
    ll a,b,n;
    cin>>n;
    if(n%2==0)
    {
        cout<<n+6<<" "<<6;
    }
    else{
        for(ll x=4; x<=1000000000; x+=2)
        {
            if((x+n)%2 ==0 or (x+n)%3==0)
            {
                cout<<x+n<<" "<<x;
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

