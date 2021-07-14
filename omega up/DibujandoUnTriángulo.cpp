#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k=1;
    for(int x =0; x<n and k<=n; x++,k+=2)
    {
        for(int y=0; y< n/2-x; y++)
        {
            cout<<" ";
        }
        for(int y=0; y<k; y++)
        {
            cout<<"@";
        }
        cout<<endl;
    }
}
