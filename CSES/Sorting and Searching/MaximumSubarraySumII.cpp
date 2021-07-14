#include <iostream>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    int nums[n];
    for(int x =0; x<n; x++)
    {
        cin>>nums[x];
    }

    int cuenta=nums[0];
    int res=0;
    int indice=0;
    bool a;
    for(int x=1; x<n; x++)
    {
        if(a)
        {
            if(cuenta<cuenta+nums[x])
            {
                cuenta=cuenta+nums[x];
                indice=0;
            }
        }
        res=max(cuenta,res);
        indice++;
    }
    cout<<res;
}
