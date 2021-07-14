
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
unordered_map <ll , ll> mapa;
ll solve(ll num)
{
    if(num<4)return 10;
    if(mapa[num-2]==0)
    mapa[num-2]=solve(num-2);
    if(mapa[num-4]==0)
    mapa[num-4]=solve(num-4);
    return mapa[num-2] +mapa[num-4] + 30;
}
int main()
{
    ll num;
    cin>>num;
    cout<<solve(num);
}
