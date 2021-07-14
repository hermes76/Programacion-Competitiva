#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int res=m;
    n--;
    while(n--)
    {
        res+=m-2;
    }
    cout<<res<<endl;
}
