#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int c;
    int x=0;
    int res=-1;
    for(x=0; x<n; x++)
    {
        cin>>c;
        m-=c;
        if(m<=0 and res==-1)
        {
            res=x+1;
        }
    }
    cout<<res;
}
