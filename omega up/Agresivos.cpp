#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define all(x) x.begin(), x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
bool isgood(ll n, ll prog, ll k)
{
    ll cuenta=2;
    ll ant=vll[0];
    for(int x=1; x<n-1; x++)
    {
        if(vll[x]-ant>=k)
        {
            cuenta++;
            ant=vll[x];
        }
        if(cuenta==prog)
        {
            if(vll[n-1]-ant>=k)
                return 1;
            else
                return 0;
        }

    }
    return 0;
}
ll solve(ll n, ll prog)
{
    ll k=0;
    for(ll x=1e9/2; x>0; x/=2)
        while(isgood(n,prog,k+x))k+=x;
    return k;
}
int main()
{
    ll n,m,num;
    cin>>n>>m;
    forr(0,n,1)
    {
        cin>>num;
        vll.push_back(num);
    }
    sort(all(vll));
    cout<<solve(n,m);
}
