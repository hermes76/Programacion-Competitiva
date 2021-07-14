#include <iostream>
#include <map>
using namespace std;
map<int,int> arr;
int main()
{
    map<int,int>arr;
    int n;
    cin>>n;
    int f;
    int cuenta=0;
    for(int x =0; x<n; x++)
    {
        cin>>f;
        if(arr[f]==0)
        {
            cuenta++;
        }
        arr[f]=1;
    }
    cout<<cuenta;
}
