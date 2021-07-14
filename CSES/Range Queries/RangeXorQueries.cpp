#include <iostream>
#define MAX 262144
using namespace std;
int n,m;
int arr[MAX*2];
long long int sum(int k, int l)
{
    k--;
    l--;
    k+=n;
    l+=n;
    long long int suma=0;
    while(k<=l)
    {
        if(k%2==1)suma=(suma^arr[k++]);
        if(l%2==0)suma=(suma^arr[l--]);
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
    for(int x=n; x<2*n; x++) cin>>arr[x];
    for(int x=2*n; x<MAX*2; x++) arr[x]=0;
    for(int x=n-1; x>=0; x--) arr[x]=arr[x*2]^arr[x*2+1];
    int k,l;
    while(m--)
    {
        cin>>k>>l;
        cout<<sum(k,l)<<endl;
    }
}
