#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve()
{
    string arr[9];
    for(ll x=0; x<9; x++)
        cin>>arr[x];

    char num='1';
    bitset<9> columnas;
    bitset<9> filas;
    filas.reset();
    columnas.reset();
    bool acept;
    char numero;
    for(ll x=0; x<9; x+=3)
    {
        for(ll y=0; y<9; y+=3)
        {
            acept=0;
            numero='0';
            while(!acept)
            {
                numero+=1;
                for(ll z=x; z<x+3; z++)
                {
                    for(ll a=y; a<y+3; a++)
                    {
                        if(columnas[z]==0 && arr[z][a]!=numero && filas[a]==0)
                        {
                            arr[z][a]=numero;
                            columnas[z]=1;
                            filas[a]=1;
                            acept=1;
                            break;
                        }
                    }
                     if(acept)
                            break;
                }

            }
        }
    }

    for(ll x=0; x<9; x++)
        cout<<arr[x]<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();
}

