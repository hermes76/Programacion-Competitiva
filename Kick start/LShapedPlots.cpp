#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;
bool arr[1001][1001];
ll max1(ll a, ll b)
{
    if(a>b)
        return a;
    return b;
}
ll min1(ll a, ll b)
{
    if(a<b)
        return a;
    return b;
}
ll check(int sumaVert, int sumaHor)
{
    ll suma=0;
    ll aux1;
    ll aux2;
    ll cuenta;
    if(sumaVert>3 or sumaHor>3)
    {
      //  cout<<sumaVert<<" "<<sumaHor;
        if(sumaVert==sumaHor)
         while(sumaVert>1 and sumaHor>1)
        {
            suma++;
            sumaVert/=2;
            sumaHor/=2;
        }else
        {
            aux1=sumaVert;
            sumaVert=max1(sumaVert,sumaHor);
            sumaHor=min1(sumaHor, aux1);
            if(sumaHor*2>=sumaVert)
                aux1=sumaVert/2;
            suma+=aux1-1;
          //  cout<<suma<<endl;
            cuenta=2;
            while(cuenta*2<= sumaHor)
            {
                suma++;
                cuenta++;
            }
         //  cout<<" "<<suma<<endl;
        }

    }
    return suma;
}
ll down(int n, int m)
{
    ll sumaHorizontal;
    ll sumaVertical;
    ll suma=0;
    for(int x=0; x<m; x++)
    {
        sumaVertical=0;
        for(int y=0; y<n; y++)
        {
            if(arr[y][x]) sumaVertical++;
            else sumaVertical=0;
            sumaHorizontal=1;
            for(int z=x+1; z<m and arr[y][z]; z++) sumaHorizontal++;
            if(sumaHorizontal>1 and sumaVertical >=2) suma+=check(sumaVertical, sumaHorizontal);
            sumaHorizontal=1;
            for(int z=x-1; z>=0 and arr[y][z]; z--) sumaHorizontal++;
            if(sumaHorizontal>1 and sumaVertical >=2) suma+=check(sumaVertical, sumaHorizontal);
        }
    }
    return suma;
}
ll up(int n, int m)
{
    ll sumaHorizontal;
    ll sumaVertical;
    ll suma=0;
    for(int x=0; x<m; x++)
    {
        sumaVertical=0;
        for(int y=n-1; y>=0; y--)
        {
            if(arr[y][x]) sumaVertical++;
            else sumaVertical=0;
            sumaHorizontal=1;
            for(int z=x+1; z<m and arr[y][z]; z++) sumaHorizontal++;
            if(sumaHorizontal>1 and sumaVertical >=2) suma+=check(sumaVertical, sumaHorizontal);
            sumaHorizontal=1;
            for(int z=x-1; z>=0 and arr[y][z]; z--) sumaHorizontal++;
            if(sumaHorizontal>1 and sumaVertical >=2) suma+=check(sumaVertical, sumaHorizontal);
        }
    }
    return suma;
}
int solve(int n, int m)
{
     return up(n,m)+down(n,m);
    //return down(n,m);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    for(int x=1; x<=t; x++)
    {
        cin>>n>>m;
        for(int y=0; y<n; y++)
            for(int z =0; z<m; z++)
                cin>>arr[y][z];
        cout<<"Case #"<<x<<": "<<solve(n,m)<<endl;
    }
}
