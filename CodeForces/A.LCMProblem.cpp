#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,b;
    for(int x =0; x<n; x++)
    {
        cin>>a>>b;
        if(a*2>b)
        {
            cout<<"-1 -1"<<endl;
        }else{
            cout<<a<<" "<<a*2<<endl;
        }
    }
}
