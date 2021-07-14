#include <iostream>
using namespace std;
int main()
{
    int n,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n/4+n/4+n/2==n)
            cout<<n/2<<" "<<n/4<<" "<<n/4;
        else if(n%2==1)
        {
            n--;
            cout<<n/2<<" "<<n/2<<" "<<1;
        }
        else
        {
            n-=2;
            cout<<n/2<<" "<<n/2<<" "<<2;
        }
        cout<<endl;
    }
}
