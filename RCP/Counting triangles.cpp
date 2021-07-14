#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a,b;
    long long int res;
    while(n--)
    {
        cin>>a>>b;
        a++;
        res=(a*(a+1))/2;
        res%=1000000007;
        res*=b+1;
        res%=1000000007;
        cout<<res<<endl;
    }
}
