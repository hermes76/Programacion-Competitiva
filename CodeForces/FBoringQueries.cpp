#include <iostream>
#define MAX 262144
#define mod 1000000007
using namespace std;
int n,m;
long long int arr[MAX*2];
long long int GCD(long long int a,long long int b)
{
    if(b==0)
        return a;
    return(GCD(b,a%b));
}
long long int LCM(long long int a ,long long int b)
{
    return(a/GCD(a,b))*b;
}
long long int sum(int k, int l)
{
    k--;
    l--;
    k+=n;
    l+=n;
    long long int suma=1;
   /* if(k%2==1)suma=arr[k++];
    if(l%2==0)suma=arr[l--];
    k/=2;
    l/=2;*/
    while(k<=l)
    {
        if(k%2==1)suma=LCM(suma,arr[k++])%mod;
        if(l%2==0)suma=LCM(suma,arr[l--])%mod;
        k/=2;
        l/=2;
    }
    return suma%mod;
}
int main()
{
    long long int last=0;
    long long int lef,rig;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int x=n; x<2*n; x++) cin>>arr[x];
    for(int x=2*n; x<MAX*2; x++) arr[x]=1;
    for(int x=n-1; x>=0; x--)arr[x]=LCM(arr[x*2],arr[x*2+1])%mod;
    long long int k,l;
    cin>>m;
    while(m--)
    {

        cin>>k>>l;
        lef=(last+k)%n+1;
        rig=(last+l)%n+1;
        last=sum(min(lef,rig),max(lef,rig));
        cout<<last<<endl;
    }
}
