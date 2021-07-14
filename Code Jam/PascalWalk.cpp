#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m;
    for(int x =0; x<n; x++)
    {
        cin>>m;
        cout<<"Case #"<<x+1<<":"<<endl;
        for(int y=0; y<m; y++)
        {
            cout<<1<<" "<<y+1<<endl;
        }
    }
}