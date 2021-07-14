#include <iostream>
using namespace std;
int n,m;
int arr[100];
int value[1000000];
bool resolve[1000000];
int solve(int x)
{
    if(x<0) return 10e7;
    if(x==0)return 0;
    if(resolve[x]) return value[x];
    int best =10e7;
    for(int z=0; z<n; z++)
    {
        best= min(best,solve(x-arr[z])+1);
    }
    value[x]=best;
    resolve[x]=true;
    return best;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    int p= solve(m);
    if(p==10e7)
    {
        cout<<-1;
    }else{
    cout<<p;}
}
