#include <iostream>
#include <math.h>
using namespace std;
long long int men(long long int a, long long int b)
{
    if(a<b)
        return a;
    return b;
}
long long int ceil2(float a)
{
    long long int res=a;
    if(res<a)
        return res+1;
    return res;
}
int main()
{
    long long int n;
    cin>>n;
    long long int menor;
    bool activador;
    while(n--)
    {
        activador=0;
        long long int arr[4];
        for(int x=0; x<4; x++)cin>>arr[x];
        menor=1e18;
        float aux;
        for(int x=1; x<4; x++)
        {
            aux= (float)arr[0]/arr[x];
            menor=men(ceil2(aux)*arr[x],menor);

        }
        cout<<menor-arr[0]<<endl;
    }
}
