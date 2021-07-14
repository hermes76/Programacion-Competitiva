#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
bool isgood(double k, double n)
{
    if((k*k)+ sqrt(k)<=n)
        return 1;
    return 0;
}
double solve(double n)
{
    double k=0;
    for(double x=1e10; x>=0.000000009; x/=2)
    {
        while(isgood(k+x,n))k+=x;
    }
    return k;
}
int main()
{
    double n;
    cin>>n;
    cout<<setprecision(8)<<solve(n);
}
