#include <iostream>
using namespace std;

int main()
{
    cin.tie();
    ios::sync_with_stdio(NULL);
    int n,t,d,res=0;
    int tan;
    int dan;
    cin>>n;
    cin>>tan;
    cin>>dan;
    for(int x =1; x<n; x++)
    {
        cin>>t;
        cin>>d;
        res=max(res,(d-dan)/(t-tan));
        tan=t;
        dan=d;
    }
    cout<<res<<endl;
}