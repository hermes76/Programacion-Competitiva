#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int x =0; x<n; x++)
    {
        for(int y =0; y<m; y++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}