#include <iostream>
using namespace std;
int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    if(n==0)
    {
        cout<<0;
    }else{
    n-=m;
    n-=(n/(c+1)*(c+1));
    m+=n;
    cout<<m;
    }
}