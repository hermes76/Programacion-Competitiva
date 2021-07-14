
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
char cad[20];
void solve(ll monedas, ll indice)
{
    if(indice<0){
        while(monedas--)
            cout<<cad[monedas];
        cout<<"\n";
        return;
    }
    cad[indice]='A';
    solve(monedas, indice-1);
    cad[indice]='X';
    solve(monedas, indice-1);


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll monedas;
    cin>>monedas;
    for(int x=0; x<20; x++)
        cad[x]=0;
    solve(monedas,monedas-1);
}
