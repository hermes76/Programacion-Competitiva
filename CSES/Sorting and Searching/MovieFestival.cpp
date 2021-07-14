#include <iostream>
#include <algorithm>
using namespace std;

struct pos
{
    int a,b;
};
bool comp(pos a, pos b)
{
    return a.a<b.a;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    pos greedy;
    cin>>n;
    pos arr[n];
    for(int x =0; x<n; x++) cin>>arr[x].a>>arr[x].b;
    sort(arr,arr+n,comp);
    int res=1;
    greedy=arr[0];
    for(int x=1; x<n; x++)
    {
        if(greedy.b<=arr[x].a)
        {
            greedy=arr[x];
            res++;
        }
        else{
            if(arr[x].a>=greedy.a && arr[x].a<greedy.b && arr[x].b<=greedy.b)
            {
                greedy=arr[x];
            }
        }

    }
    cout<<res;

}
