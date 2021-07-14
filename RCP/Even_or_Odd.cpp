#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int res= (n*(n+1)/2)%2;
    int res2=(((n)*(n+1)/2)-1+(n+1))%2;
    if(res==0 && res2==0)
    {
        cout<<"Even"<<endl;
    }
    else if(res==1 and res2==1)
    {
        cout<<"Odd"<<endl;
    }
    else{
        cout<<"Either"<<endl;
    }
}