#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=n/3;
    int b= n/2-n/6;
    cout<<a<<" "<<b<<" ";
    n-=a+b;
    cout<<n;
}
