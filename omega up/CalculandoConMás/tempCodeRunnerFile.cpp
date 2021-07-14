#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    float res;
    if(b!=0)
    {
    res=float(a)/b+c;
    cout<<res;
    if(res!=float(a)/b-c)
    {
    res=float(a)/b-c;
    cout<<" "<<res;
    }
    }else{
        cout<<"indefinido";
    }
}