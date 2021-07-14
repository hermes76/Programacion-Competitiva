#include <iostream>
#include <queue>
using namespace std;
struct p
{
    int x,y,dir;
};
int ejex[4]={0,-1,0,1};
int ejey[4]={-1,0,1,0};
char letra[4]={'U','L','D','R'};
char cadenas[1002][1002];
queue <p> cola;
int n,m;
p j;
p f;
bool arr[1002][1002];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    char t;
    for(int x =m+1; x>=0; x--)
    {
        arr[x][0]=0;
        arr[x][n+1]=0;
    }
    for(int x=n+1; x>=0; x--)
    {
        arr[0][x]=0;
        arr[m+1][x]=0;
    }
    for(int x =1; x<n+1; x++)
    {
        for(int y=1; y<m+1; y++)
        {
            cin>>t;
            t-=35;
            arr[x][y]=t;
            if(t==30)j.x=y,j.y=x;
            else if(t==31) f.x=y,f.y=x;
            cadenas[x][y]='.';
        }
    }
    arr[j.y][j.x]=0;
    j.dir=3;
    cola.push(j);
    p aux;
    string cad;
    while(!cola.empty())
    {   
        aux=cola.front();
        cadenas[aux.y][aux.x]=letra[aux.dir];
        if(aux.x==f.x and aux.y==f.y)
                {
                    while(f.x!= j.x or f.y!=j.y)
                    {
                        cad+=cadenas[f.y][f.x];
                        if(cadenas[f.y][f.x]=='U')f.y+=1;
                        else if(cadenas[f.y][f.x]=='R')f.x-=1;
                        else if(cadenas[f.y][f.x]=='D')f.y-=1;
                        else if(cadenas[f.y][f.x]=='L')f.x+=1;
                    }
                    cout<<"YES"<<"\n"<<cad.length()<<"\n";
                    for(int x =cad.length()-1;x>=0; x--)
                    {
                        cout<<cad[x];
                    }
                    return 0;
                }
        cola.pop();
        for(int x =3; x>=0; x--)
        {
            p esta=aux;
            esta.x+=ejex[x];
            esta.y+=ejey[x];
            if(arr[esta.y][esta.x])
            {
                arr[esta.y][esta.x]=0;
                esta.dir=x;
                cola.push(esta);
            }
        }
    }
    cout<<"NO";


}