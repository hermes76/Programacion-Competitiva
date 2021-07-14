#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==1)
        cout<<1;
    else if(n>3)
       {
        for(int x=n-1; x>=1; x-=2)
            cout<<x<<" ";
        for(int x=n; x>=1; x-=2)
            cout<<x<<" ";
       }
       else cout<<"NO SOLUTION";

}
