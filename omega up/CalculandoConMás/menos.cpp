#include <iostream>
using namespace std;

int main()
{
    float a,b,c;
    cin>>a>>b>>c;
    float res;
    if(b!=0)
    {
        res=a/b+c;
        cout<<res;
        if(res!=a/b-c)
        {
            res=a/b-c;
            cout<<" "<<res;
        }
    }else{
        cout<<"indefinido";
    }
}