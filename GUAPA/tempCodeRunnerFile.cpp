#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int b;
    int c;
    long long int a;
    while(n--)
    {
        cin>>b;
        a=10;
        if(b>=2)
        {
            a=a*9;
            b-=2;
            c=b%10;
            b/=10;
            for(int x =0; x<b; x++)
            {
                a*=pow(8,10);
                a%=999999929;
            }
            a*=pow(8,c);
            a%=999999929;
        }
        cout<<a<<'\n';
    }
}