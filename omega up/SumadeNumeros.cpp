#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    long long int res=0;
    for(int x =0; x<n; x++){cin>>a; res+=a;}
    cout<<res;
}
