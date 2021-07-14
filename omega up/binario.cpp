
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

void solve(ll num)
{
    if(num)
    {
        solve(num/2);
        if(num%2==0)cout<<0;
        else cout<<1;
        cout<<" ";
    }
}
int main()
{
    ll num;
    cin>>num;
    solve(num);
}
