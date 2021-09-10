
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
ll posx[4]={-1,0,1,0};
ll posy[4]={0,1,0,-1};
char dir[4]={'L','D','R','U'};
int bs[1000][1000];
string arr[1000];
void BFS(ll i,ll j,ll n,ll m, ll relleno)
{
     queue<tuple<ll ,ll,ll>> cola;
     bool acept=0;
    cola.push(make_tuple(i,j,relleno));
    bs[i][j]=relleno;
    while(!cola.empty())
    {
        tuple<ll,ll,ll> aux=cola.front();
        cola.pop();
        for(ll x=0; x<4; x++)
        {
            tuple<ll,ll,ll> sum=aux;
            get<0>(sum)+=posy[x];
            get<1>(sum)+=posx[x];
            get<2>(sum)++;
            if(get<0>(sum)>=0 && get<0>(sum)<n && get<1>(sum)>=0 && get<1>(sum)<m && (arr[get<0>(sum)][get<1>(sum)] =='.' || arr[get<0>(sum)][get<1>(sum)]=='E'))
            {
                if(bs[get<0>(sum)][get<1>(sum)]==-1)
                {
                    bs[get<0>(sum)][get<1>(sum)]=get<2>(sum);
                    cola.push(sum);
                }
            }
        }
    }
}
ll solve()
{
    ll n,m;
    ll finalX,finalY;
    cin>>n>>m;
    for(ll x=0; x<n; x++)
        for(ll y=0; y<m; y++)
            bs[x][y]=-1;
    for(ll x=0; x<n; x++)
            cin>>arr[x];
    for(ll x=0; x<n; x++)
    {
        for(ll y=0; y<m; y++)
        {
            if(arr[x][y]=='E')
            {
                finalX=x;
                finalY=y;
                BFS(x,y,n,m,0);
            }
        }
    }
    ll q,a,b;
    ll sumA,sumB;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        a--;
        b--;
        if(arr[a][b]=='#')
            cout<<"W";
        else if(arr[a][b]=='X')
            cout<<"X";
        else if(arr[a][b]=='E')
            cout<<"E";
         else if(arr[a][b]=='.')
         {
            if(bs[a][b]!=-1)
            {
                for(ll x=0; x<4; x++)
                {
                    sumA=a+posy[x];
                    sumB=b+posx[x];
                    if(sumA>=0 && sumA <n && sumB>=0 && sumB<m && (arr[sumA][sumB]=='.'||arr[sumA][sumB]=='E') && bs[sumA][sumB]<bs[a][b])
                    {
                       cout<<dir[x];
                       break;
                    }

                }
            }else
                cout<<'?';

         }
          cout<<"\n";


    }
    /*for(ll x=0; x<n; x++)
          {
              for(ll y=0; y<m; y++)
              {
                  cout<<bs[x][y];
              }
              cout<<endl;
          }*/
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

