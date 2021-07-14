#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    map<int,int>pos;
    int n,k;
    cin>>n>>k;
    int nums[n];
    int cuenta=0;
    int iguales;
    int maximo=0;
    int posx=0;
    for(int x =0; x<n; x++)
    {
        cin>>nums[x];
        pos[nums[x]]++;
    }
    for(int x =0; x<n; x++)
    {
        if(maximo<pos[nums[x]])
        {
            maximo=pos[nums[x]];
            posx=x;
        }
    }
    sort(nums,nums+n);
    cuenta=0;
    for(int x =0; x<n; x++)
    {
        if(cuenta+maximo>=k)
        {
            cout<<cuenta+1;
            break;
        }
        if(nums[posx]>nums[x])
        {
            cuenta+=nums[posx]-nums[x];
        }
        else if(nums[posx]<nums[x]){
            cuenta+=nums[x]-nums[posx];
        }
    }
}
