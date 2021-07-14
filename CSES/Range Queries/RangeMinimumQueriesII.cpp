#include <iostream>
#define INF 1e9;
#define MAX 262144
using namespace std;

int n,m;
int arr[2*MAX];
void update(int k,int l)
{
    k--;
    k+=n;
    arr[k]=l;
    while(k>0)
    {
        if(k%2==1)k--;
        arr[k/2]=min(arr[k],arr[k+1]);
        k/=2;
    }
}
int minix(int k,int l)
{
    k--;
    l--;
    k+=n;
    l+=n;
    int mini=INF;
    while(k<=l)
    {
        if(k%2==1)mini=min(mini,arr[k++]);
        if(l%2==0) mini=min(mini,arr[l--]);
        l/=2;
        k/=2;
    }
    return mini;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int x=n; x<2*n; x++) cin>>arr[x];
    for(int x =2*n; x<MAX*2; x++) arr[x]=INF;
    int indice= n/2;
    int aux=n;
    while(indice>0)
    {
        arr[indice] = min(arr[indice*2],arr[indice*2+1]);
        if(indice==n-1)
        {
            indice=aux/4;
            aux/=2;
        }else indice++;
    }
    arr[0]=min(arr[1],arr[2]);
    int a,b,c;
    while(m--)
    {
        cin>>a>>b>>c;
        if(a==1)update(b,c);
        else cout<<minix(b,c)<<endl;
    }
}
