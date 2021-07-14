#include <iostream>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    int res;
    p=p%3;
    res=n-p;
    if( res<=0)
    {
        res= 3+res;
    }
    cout<<res<<" ";
    res=n+p;
    if(res>=4)
    {
        res=res-3;
    }
    cout<<res;
}