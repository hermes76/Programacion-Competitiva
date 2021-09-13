#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
string grid[10];
ll solve(char pieza)
{
    char aux[10][10];
    for(ll x=0; x<10; x++)
        for(ll y=0; y<10; y++)
            aux[x][y]=grid[x][y];

    for(ll x=0; x<10; x++)
        for(ll y=0; y<10; y++)
            if(aux[x][y]==pieza)
                aux[x][y]='.';

    char letra;
    bool aceptable;
    for(ll x=0; x<9; x++){
        for(ll y=0; y<10;)
        {
            if(aux[x][y]!='.')
            {
                letra=aux[x][y];
                aceptable=0;
            }
            else y++;
            while(aux[x][y]!='.' && aux[x][y]==letra)
            {
                if(aux[x+1][y]!='.')
                    aceptable=1;
                y++;
                 if(aux[x][y]!=letra && aux)
                {
                    if(aceptable==0)
                    {
                        cout<<"Pieza "<<pieza<<" no se puede remover\n";
                        return 0;
                    }
                }
            }

        }
    }

    cout<<"Pieza "<<pieza<<" removida"<<"\n";
    for(ll x=0; x<10; x++)
        for(ll y=0; y<10; y++)
            grid[x][y]=aux[x][y];
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll x=0; x<10; x++)
        for(ll y=0; y<10; y++)
            cin>>grid[x][y];
    ll t,a;
    char pieza;
    cin>>t;
    char arr[t];
    for(ll x=0; x<t; x++)
    {
        cin>>arr[x];
    }
    for(ll x=0; x<t; x++)
    {
        if(!solve(arr[x]))
            break;
    }
    for(ll x=0; x<10; x++)
    {
        for(ll y=0; y<10; y++)
        {
            cout<<grid[x][y];
        }
        cout<<"\n";
    }
}

