#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int a;
    long long int cuenta;
    for(int x =0; x<k; x++)
    {
        cin>>a;
        if(a<=1000)
        {
            cuenta=a*n;
        }else
        {
            cuenta=1000*n;
            cuenta+=(a-1000)*m;
        }
        cout<<a<<" "<<cuenta<<endl;
    }
}
