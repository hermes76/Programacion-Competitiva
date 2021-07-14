
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
int nums[6];
void solve(ll caras, ll lanzamientos, ll local)
{
    if(local>=lanzamientos)
    {
        for(int x=0; x<lanzamientos; x++)
            cout<<nums[x];
        cout<<"\n";
        return;
    }
    for(int x=0; x<caras; x++)
    {
        nums[local]= x+1;
        solve(caras, lanzamientos, local+1);
    }
}
int main()
{
    ll caras, lanzamientos;
    cin>>caras>>lanzamientos;
    solve(caras, lanzamientos,0);
}
