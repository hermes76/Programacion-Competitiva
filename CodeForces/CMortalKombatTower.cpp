#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        int res=0;
        bool arr[m];
        for(int x =0; x<m; x++)cin>>arr[x];
        for(int x =0; x<m;)
        {
            if(arr[x]&1)
            {
                res++;
                x++;
                if(x<m)
                {
                    x++;
                }
            }else{
                x++;
                if(x<m)
                {
                    if(!arr[x]&1)
                    {
                        x++;
                    }
                }

            }

            x++;
            if(x<m)
            {
                if(arr[x]&1)
                {
                    x++;
                }
            }
        }
        cout<<res<<endl;
    }
}
