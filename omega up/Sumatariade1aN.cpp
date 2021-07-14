#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a;
    long long res;
    while(n--)
    {
        cin>>a;
        res=(a*(a+1))/2;
        cout<<res<<" "<<res<<" "<<res<<endl;
    }
}
