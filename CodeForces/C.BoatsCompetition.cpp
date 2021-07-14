#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int arr[1000];
int main()
{
    #ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int b;
    int i,j;
    int mayor;
    int mj;
    for(int x =0; x<n; x++)
    {
        cin>>b;
        for(int y=0; y<b; y++)
        {
            cin>>arr[y];
        }
        sort(arr,arr+b);
        mj=0;
        for(int x =1; x<=b+b; x++)
        {
            int y=b-1;
            mayor=0;
            for(int z=0; z<y;)
            {
                if(arr[z]+arr[y]==x)
                {
                    mayor++;
                    z++;
                    y--;
                }else if(arr[z]+arr[y]>x)
                    {
                        y--;
                    }else{
                        z++;
                    }
            }
            mj=max(mj,mayor);
        }
        cout<<mj<<endl;
    }
}
