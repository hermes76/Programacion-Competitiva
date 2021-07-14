//#include <iostream>
#include <bits/stdc++.h>
#define MAX 262144
using namespace std;

int n,m;
long long int arr[MAX*2];
void update(int k,int l)
{
    k--;
    k+=n;
    arr[k]=l;
    while(k>0)
    {
        if(k%2==1)k--;
     arr[k/2]=arr[k]+ arr[k+1];
        k/=2;
    }
}
long long int sum(int k, int l)
{
    k--;
    l--;
    k+=n;
    l+=n;
    long long int suma=0;
    while(k<=l)
    {
        if(k%2==1)suma+=arr[k++];
        if(l%2==0)suma+=arr[l--];
        k/=2;
        l/=2;
    }
    return suma;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int x =n; x<n*2; x++)cin>>arr[x];
    for(int y=n*2; y<MAX*2; y++)arr[y]=0;
    int b,k,l;
    int indice =n/2;
    int aux=n;
    while(indice>0)
    {
        arr[indice]= arr[indice*2]+arr[indice*2+1];
        if(indice==aux-1)
        {
            indice=aux/4;
            aux/=2;
        }else indice++;
    }
    arr[0]=arr[1];
    while(m--)
    {
        cin>>b>>k>>l;
        if(b==1)update(k,l);
        else cout<<sum(k,l)<<endl;
    }
}
