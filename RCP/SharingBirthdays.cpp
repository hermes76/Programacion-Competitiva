#include <iostream>
using namespace std;
bool arr[12][31];
int main()
{
    int n;
    cin>>n;
    int mm,dd;
    char t;
    int res=0;
    for(int x=0; x<n; x++)
    {
        cin>>mm>>t>>dd;
        mm--;
        dd--;
        arr[mm][dd]=1;
    }
    for(int x=0; x<12; x++)
    {
        for(int y =0; y<31; y++)
        {
            if(arr[x][y]==1)
            {
                res++;
            }
        }
    }
    cout<<res<<endl;
}
