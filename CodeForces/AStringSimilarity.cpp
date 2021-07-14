#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        string arr;
        cin>>arr;
        for(int x =0; x<a*2-1; x+=2)
        {
            cout<<arr[x];
        }
        cout<<'\n';
    }
}
