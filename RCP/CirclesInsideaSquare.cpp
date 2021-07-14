#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    cout<<setprecision(6);
    double n;
    cin>>n;
    double res;
    res=n*4;
    res+=2*n*.9318509512;
    res*=res;
    cout<<res<<endl;

}
