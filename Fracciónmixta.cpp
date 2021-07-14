#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<n/m;
    if(n%m!=0)
    {
        cout<<' '<<n%m<<'/'<<m;
    }

}
