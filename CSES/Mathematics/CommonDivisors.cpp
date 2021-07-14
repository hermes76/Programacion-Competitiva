#include <iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0){return a;}
    return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    int a;
    int b;
    cin>>a>>b;
    int valor;
    n-=2;
    valor= gcd(a,b);
    while(n--)
    {
        cin>>a;
        valor= gcd(a,valor);
        cout<<valor<<endl;
    }
    cout<<valor;
}