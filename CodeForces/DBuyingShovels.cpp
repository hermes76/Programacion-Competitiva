#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b;
    int maxi=a;
    while(n--)
    {
        cin>>a>>b;
        maxi=a;
        if(a%b==0)
            cout<<a/b;
        else if(b>=a)
            cout<<1;
        else
        {
            for(int x=1; x*x<=a; x++)
            {
                if(a%x==0)
                {
                    if(x<=b)
                        maxi=min(maxi,a/x);
                    if(a/x<=b)
                        maxi=min(maxi,x);
                }
            }
            cout<<maxi;
        }
        cout<<endl;

    }
}
