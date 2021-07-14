#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k=1;
    int cuenta=k+7;
    while(cuenta<n)
    {
        k++;
        cuenta+=k+7;
    }
    cout<<k;

}