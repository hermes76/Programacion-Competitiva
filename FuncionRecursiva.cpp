#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long int n,m;
    cin>>m;
    while(m--)
    {
        cin>>n;
        cout<<n<<"/"<<2*n+1<<"\n";
    }
}

