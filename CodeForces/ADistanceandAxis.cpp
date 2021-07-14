#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    int res;
    while(n--)
    {
        cin>>a>>b;
        if(a>b)
        {
            res=0;
            if(b%2==0)
            {
                if(a%2==0)res=0;
                else
                    res=1;

            }
            else{
                if(a%2==1)
                    res=0;
                else res=1;
            }
        }
        else res=b-a;
        cout<<res<<endl;
    }
}
