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
    ll n;
    cin>>n;
    string cad[n];
    for(ll x=0; x<n; x++)
        cin>>cad[x];
    pair<ll,ll> puntos[2];
    ll indice=0;
    for(ll x=0; x<n; x++)
        for(ll y=0; y<n; y++)
            if(cad[x][y]=='*')
            {
                puntos[indice].first=x;
                puntos[indice].second=y;
                indice++;
            }

    if(puntos[0].first!=puntos[1].first && puntos[0].second != puntos[1].second)
    {
        cad[puntos[0].first][puntos[1].second]='*';
         cad[puntos[1].first][puntos[0].second]='*';
    }
    else if(puntos[0].first==puntos[1].first)
    {
        if(puntos[0].first+1<n){


            cad[puntos[0].first+1][puntos[0].second]='*';
             cad[puntos[1].first+1][puntos[1].second]='*';
        }
        else {
            cad[puntos[0].first-1][puntos[0].second]='*';
             cad[puntos[1].first-1][puntos[1].second]='*';
        }
    }
    else
    {
        if(puntos[0].second+1<n){


            cad[puntos[0].first][puntos[0].second+1]='*';
             cad[puntos[1].first][puntos[1].second+1]='*';
        }
        else {
            cad[puntos[0].first][puntos[0].second-1]='*';
             cad[puntos[1].first][puntos[1].second-1]='*';
        }
    }
    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<n; y++)
        {
            cout<<cad[x][y];
        }
        cout<<endl;
    }
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

