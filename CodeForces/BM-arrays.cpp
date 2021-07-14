#include <iostream>
using namespace std;

int main()
{
    int t,n,k;
    cin>>t;
    int aux;
    while(t--)
    {
        cin>>n>>k;
        for(int x=0; x<k-3; x++)
            cout<<1<<" ";
        n-=(k-3);
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
