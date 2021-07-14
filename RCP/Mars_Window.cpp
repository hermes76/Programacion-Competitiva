#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,n2;
    cin>>n;
    n2=n;
    float poder,poder2;
    if(n==2018)
    {
        cout<<"yes"<<endl;
    }else if(n==2019)
    {
        cout<<"no"<<endl;
    }else{
    n-=2018;
    poder = (26.0/13)*(n/2);
    poder2=poder+.305;
    int trunc= poder2;
    if(n%trunc==0)
    {
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    }

}