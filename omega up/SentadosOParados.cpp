#include <iostream>
using namespace std;

int main()
{
    long long int n,m,c,res;
    cin>>n>>m>>c;
    res=n*m;
    if(res<=c)cout<<res<<" "<<c-res;
    else cout<<c<<" "<<0;
}
