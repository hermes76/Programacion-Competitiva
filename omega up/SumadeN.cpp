#include <iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int res=0;
    for(int x=0; x<a.length(); x++)
    {
        res+=a[x]-48;
    }
    cout<<res;
}
