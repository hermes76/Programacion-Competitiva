#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int  a,par,imp;
    for(int x =0; x<n; x++){cin>>a; if(a%2&1) imp++; else par++;}
    if(par<imp)
        cout<<"JAMES";
    else if (par>imp)
        cout<<"FRED";
    else cout<<"DRAW";
}
