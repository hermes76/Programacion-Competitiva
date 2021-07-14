#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b;
    int res;
    int mod;
    while(n--)
    {
        cin>>a>>b;
        mod=a%b;
        if(mod!=0)
        {
            mod=b-mod;
        }
        cout<<mod<<endl;
    }
}
