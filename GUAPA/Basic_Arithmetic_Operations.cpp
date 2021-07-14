#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int p;
    double a,b;
    int n;
    double num;
    long long int res;
    int digito;
    cin>>p;
    while(p--)
    {
        cin>>a>>b>>n;
        num=a/b;
        res=1;
        digito=num;
        num-=digito;
        while(n--)
        {
            num*=10;
            digito=num;
            if(!digito)
            {
                res*=7;
            }else{
                res*=digito;
            }
            res%=999999937;
            num-=digito;
        }
        cout<<res<<'\n';
    }
}