#include <iostream>
#define INF 1000000000
#define MAX 262144
using namespace std;
int n,m,k,l;
int arr[2*MAX];
int minix(int a, int b)
{
    a--;
    b--;
    a+=MAX; b+=MAX;
    int mini=1000000000;
    while(a<=b)
    {
        if(a%2==1) mini=min(mini,arr[a++]);
        if(b%2==0) mini=min(mini,arr[b--]);
        a/=2; b/=2;
    }
    return mini;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int x=MAX; x<MAX+n; x++) cin>>arr[x];
    for(int x=MAX+n; x<2*MAX; x++) arr[x]=INF;
    int indice =MAX/2;
    int aux=MAX;
    while(indice>0)
    {
        arr[indice]= min(arr[indice*2],arr[indice*2+1]);
        if(indice==aux-1)
        {
            indice=aux/4;
            aux/=2;
        }else indice++;
    }
    arr[0]=min(arr[1],arr[2]);
    while(m--)
    {
        cin>>k>>l;
        cout<<minix(k,l)<<endl;
    }
}
