#include <iostream>
using namespace std;

bool solve()
{
    int n,k,k2,w,b;
    int mini,maxi;
    int minib,maxib;
    cin>>n>>k>>k2>>w>>b;
    mini=min(k,k2);
    maxi=max(k,k2);
    minib=n-maxi;
    maxib=n-mini;
    w-=mini;
    maxi-=mini;
    w-=maxi/2;
    if(w>0)
        return 0;
    b-=minib;
    maxib-=minib;
    b-=maxib/2;
    if(b>0)return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        if(solve()==1)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
}
