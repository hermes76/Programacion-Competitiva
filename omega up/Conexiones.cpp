#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long int a,b;
    while(n--)
    {
        cin>>a>>b;
        cout<<a*2+b*2+1<<" "<<b*2+1<<endl;
    }
}
