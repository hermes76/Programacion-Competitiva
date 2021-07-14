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

ll solve(ll a, ll b)
{
    if(!b)
        return a;
    return solve(b,a%b);
}
int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<solve(a,b);
}
