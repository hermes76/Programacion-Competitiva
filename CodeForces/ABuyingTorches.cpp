#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int l;
    cin>>l;
    long long int n,m,k;
    long long int palos=0;
    long long int mult;
    long long int res;
    while(l--)
    {
        cin>>n>>m>>k;
        res=k;
        palos=(m*k)+k;
        palos-=n;
        res++;
        mult=palos/(n-1);
        res+=mult;
        if(mult*(n-1)+n<m*k+k)
            res++;
        cout<<res<<endl;
    }
}
