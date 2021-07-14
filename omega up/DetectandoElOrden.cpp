#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if (a==b and b==c and c==a)
    {
        cout<<"I";
    }
    else if(a<=b and b<=c and a<=c)
    {
        cout<<"C";
    }else if(a>=b and b>=c and a>=c)
    {
        cout<<"D";
    }else{
        cout<<"X";
    }
}