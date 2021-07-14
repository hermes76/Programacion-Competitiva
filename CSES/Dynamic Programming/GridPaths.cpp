#include <iostream>
#define MAX 1000
using namespace std;
int n;
char mapa[MAX][MAX];
int ejex[2]={1,0};
int ejey[2]={0,1};
long long int DP[MAX][MAX];
bool visitadosDP[MAX][MAX];
long long int A(int x, int y, int n)
{
    long long int path=0;
    if(visitadosDP[y][x])return DP[y][x];
  for(int z =0;z<2; z++)
  {
      int aux=x;
      int auy=y;
      aux+=ejex[z];
      auy+=ejey[z];
      if(aux>=0 and aux<n and auy >=0 and auy<n and mapa[auy][aux]=='.')
      {
          path+=A(aux,auy,n);
          path%=1000000007;
      }
  }
  visitadosDP[y][x]=1;
  DP[y][x]=path;
  return path;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++)cin>>mapa[x][y];
        DP[n-1][n-1]=1;
        visitadosDP[n-1][n-1]=1;
    if(mapa[0][0]=='*' or mapa[n-1][n-1]=='*')cout<<0;
    else
    cout<<A(0,0,n);
}
