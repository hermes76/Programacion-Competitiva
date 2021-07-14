#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
ll llamadas;
ll solve(ll n ,ll k)
{
    if(k==0 or k==n)
        return 1;
    llamadas+=2;
    return solve(n-1,k)+solve(n-1,k-1);
}
int main()
{
    ll n,k;
    llamadas=1;
    cin>>n>>k;
    cout<<solve(n,k)<<" ";
    cout<<llamadas;
}
