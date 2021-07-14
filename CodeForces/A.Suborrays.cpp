#include <iostream>

using namespace std;

int main()
{
    int n,a;
    cin>>n;
    for(int x =0; x<n; x++)
    {
        cin>>a;
        for(int y=1; y<=a; y++)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
