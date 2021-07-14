#include <iostream>
#define ll long long int
using namespace std;
int main()
{
    int n;
    ll a,b;
    cin>>n;
    ll res;
    while(n--)
    {
        cin>>a>>b;
        if(a<=b)
        {
            if(b%2)
                res=(b*b)-(a-1);
            else
                res=(b*b)+(a-1) - 2*(b-1);
        }else
             if(a%2)
                res=(a*a)+(b-1) - 2*(a-1);
            else
                res=(a*a)-(b-1);
        cout<<res<<'\n';
    }
}
