
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
    ll n, m;
    cin>>n>>m;
    map <ll,ll> positive;
    map <ll,ll> negative;

    ll num;

    ll sum=0;
    ll cont=0;
    for(ll x=0; x<n; x++)
        {
            cin>>num;
            sum+=num;

            if(sum>=0)
                positive[sum]++;
            else
            {
                negative[(sum)*(-1)]++;
            }
            if(sum>=m)
            {
                if(sum==m && m!=0)
                    cont++;
                cont+=positive[sum-m];
            }
            else if(sum<m)
            {
                cont+= negative[m-sum];
            }
        }
    cout<<cont;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

