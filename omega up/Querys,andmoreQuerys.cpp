#include <iostream>
using namespace std;
int res[100000];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int s;
    for(int x =n-1; x>=0; --x)
    {
        cin>>s;
        res[s]+=1;
    }
    int ins;
    cin>> ins;
    for(int x =ins-1; x>=0; --x)
    {
        cin>>s;
        cout<<res[s]<<"\n";
    }
}
