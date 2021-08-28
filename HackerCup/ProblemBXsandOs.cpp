#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
ofstream out("out.txt");
ifstream in("in.txt");
string gato[50];
bitset <50> vertical;
void solve(ll n)
{
  ll Xs;
  ll conjuntos=0;
  ll minimo=INF;
  bool aceptado;

  vertical.reset();
    ll indice;
  for(ll x=0; x<n; x++)
  {
      aceptado=1;
      Xs=0;
      for(ll y=0; y<n; y++)
      {
          if(gato[x][y]=='O')
          {
              aceptado=0;
              break;
          }
          else if(gato[x][y]=='.')
          {
            Xs++;
            indice=y;
          }
      }
      if(aceptado ==1)
      {
          if(minimo>Xs)
          {
            minimo=Xs;
            conjuntos=1;
          }else if(minimo==Xs)
            conjuntos++;
            if(Xs==1)
            {
                bool valido=1;
                for(ll z=0; z<n; z++)
                {
                    if(z==x)continue;
                    if(gato[z][indice]=='O' or gato[z][indice]=='.')
                    {
                        valido=0;
                        break;
                    }

                }
                if(valido==1)
                {
                    vertical[indice]=1;
                }
            }

      }
  }
  for(ll x=0; x<n; x++)
  {
      if(vertical[x]==1)
        continue;
    Xs=0;
      aceptado=1;
      for(ll y=0; y<n; y++)
      {
          if(gato[y][x]=='O')
          {
              aceptado=0;
              break;
          }
          else if(gato[y][x]=='.')
            Xs++;
      }
      if(aceptado ==1)
      {
         if(minimo>Xs)
          {
            minimo=Xs;
            conjuntos=1;
          }else if(minimo==Xs)
            conjuntos++;
      }
  }
  if(minimo==INF)
    out<<"Impossible\n";
  else
  out<<minimo<<" "<<conjuntos<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    ll n;
    in>>t;
    ll cont=1;
    while(t--)
    {
        in>>n;
        for(ll x=0; x<n; x++)
                in>>gato[x];
        out<<"Case #"<<cont<<": ";
        solve(n);
        cont++;
    }
    in.close();
    out.close();
}

