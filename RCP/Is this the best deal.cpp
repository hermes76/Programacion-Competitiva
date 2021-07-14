
#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int res;
    if(a>500)
        a-=100;
    if(b>500)
        b-=100;
    if(c>500)
        c-=100;
    cout<<a+b+c;
}
