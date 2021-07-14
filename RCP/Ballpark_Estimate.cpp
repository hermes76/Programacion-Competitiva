#include <iostream>
using namespace std;

int main()
{
    long long int n,m;
    cin>>n;
    m=n;
    int k=0;
    int espacios=0;
    while(m>10)
    {
        if(m<100)
        {
            k=m-(m/10)*10;
        }
        m/=10;
        espacios++;
    }
    long long res=1;
    if(k>=5)
    {
    
        for(int x =0; x<espacios; x++)
        {
            res*=10;
        }
        res*=m+1;
    }else{
        for(int x =0; x<espacios; x++)
        {
            res*=10;
        }
        res*=m;
    }
    cout<<res;
}