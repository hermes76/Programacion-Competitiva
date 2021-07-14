#include <iostream>
#define MAX 262144
using namespace std;
int arr[MAX*2];
int n;
int m;
void update(int a, int b)
{
     a--;
    a+=MAX;
    arr[a]=b;
    while(a>0)
    {
        if(a%2==1)a--;
        arr[a/2]=arr[a]+arr[a+1];
        a/=2;
    }
}
int GetSum(int a, int b)
{
    a--;
    b--;
    a+=MAX;
    b+=MAX;
    int suma=0;
    while(a<=b)
    {
        if(a%2==1) suma+=arr[a++];
        if(b%2==0) suma+=arr[b--];
        b/=2;
        a/=2;
    }
    return suma;
}
int main()
{
    cin>>n>>m;
    for(int x =MAX; x<MAX+n; x++)cin>>arr[x];
    for(int y=n+MAX; y<MAX*2; y++)arr[y]=0;
    for(int x =MAX-1; x>=0; x--) arr[x]=arr[x*2]+arr[x*2+1];
    cout<<endl;
    int a,b,indice,aux;
    int r;
    while(m--)
    {
        r=-1000000000;
        cin>>a>>b;
        update(a,b);
        /*for(int x =0; x<n; x++)
        {
            aux=-1000000000;
            for(int y =x; y<=(1<<n); y++)
            {
                aux=max(aux+arr[y],arr[y]);
                cout<<aux<<" "<<arr[y]<<endl;
            }
            if(r>aux) break;
            r=aux;
        }*/
        cout<<arr[0]<<endl;
    }
    cout<<endl<<endl;
   // for(int x =MAX/4; x<MAX/4+n; x++)cout<<arr[x]<<" ";
}
