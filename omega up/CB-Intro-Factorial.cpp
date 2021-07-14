
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

ll solve(ll fact)
{
    if(fact<=1)
        return 1;
    else return fact*solve(fact-1);
}
int main()
{
    ll fact;
    cin>>fact;
    cout<<solve(fact);
}
