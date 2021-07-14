
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
int permut[8];
bool elegidos[8];
int cuentas;
void solve(string cad, int len,int local)
{
    if(local>=len)
    {
        for(int x=0; x<len; x++)
            cout<<cad[permut[x]];
        cout<<"\n";
        cuentas++;
    }
    else
    for(int x=0; x<len; x++)
    {
        if(elegidos[x]==1) continue;
        permut[local]=x;
        elegidos[x]=1;
        solve(cad,len,local+1);
        elegidos[x]=0;
    }
}
int main()
{
    string cad;
    cin>>cad;
    cuentas=0;
    solve(cad,cad.length(),0);
          cout<<cuentas;
}
