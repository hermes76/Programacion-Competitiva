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
ll solve(ll fibo)
{
    if(fibo<=1)
        return fibo;
    llamadas+=2;
    return solve(fibo-1)+ solve(fibo-2);
}
int main()
{
    ll fibo;
    llamadas=1;
    cin>>fibo;
    cout<<solve(fibo)<<" ";
    cout<<llamadas;
}
