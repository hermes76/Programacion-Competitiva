#include <iostream>
using namespace std;
int jaime[2][1000];
int cameron[2][1000];
int a[1000],b[1000];
char c[1000];
int tamj;
int tamm;
int m;
int acabar=0;
int pos;
int interseccion(int cual,int indice)
{
    if(cual==0)
    {
        for(int x =0; x<tamj; x++)
        {
            if((jaime[0][x]<=a[indice] and jaime[1][x]>a[indice]) or (jaime[0][x]<b[indice] and jaime[1][x]>=b[indice]) or (jaime[0][x]>a[indice] and jaime[1][x]<b[indice]))
            {
                return 0;
            }
        }
    }else if(cual==1)
    {
         for(int x =0; x<tamm; x++)
        {
            if((cameron[0][x]<=a[indice] and cameron[1][x]>a[indice]) or (cameron[0][x]<b[indice] and cameron[1][x]>=b[indice]) or (cameron[0][x]>a[indice] and cameron[1][x]<b[indice]))
            {
                return 0;
            }
        }
    }
    return 1;
}
void recursion(int indice)
{
    if(acabar==1)
    {
        return;
    }
    if(indice<m)
    {
        if(interseccion(0,indice) and acabar==0)
        {
            c[indice]='J';
            jaime[0][tamj]=a[indice];
            jaime[1][tamj]=b[indice];
            tamj++;
            recursion(indice+1);
            tamj--;
        }if(interseccion(1,indice) and acabar==0)
        {
                c[indice]='C';
                cameron[0][tamm] =a[indice];
                cameron[1][tamm]=b[indice];
                tamm++;
                recursion(indice+1);
                tamm--;
        }
        return;
    }else{
        acabar=1;
         cout<<"Case #"<<pos+1<<": ";
        for(int x =0; x<m; x++)
        {
            cout<<c[x];
        }
        cout<<endl;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int x =0; x<n; x++)
    {
        cin>>m;
        acabar=0;
        tamm=0;
        tamj=0;
        pos=x;
        for(int y=0; y<m; y++)
        {
            cin>>a[y]>>b[y];
        }
        recursion(0);
        if(acabar==0)
        {
            cout<<"Case #"<<x+1<<": IMPOSSIBLE"<<endl;
        }
    }
}
