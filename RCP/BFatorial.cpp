#include <iostream>
using namespace std;
int arr[100];
int value[1000000];
bool resolve[1000000];
int solve(int x)
{
    if(x<0) return 10e7;
    if(x==0)return 0;
    if(resolve[x]) return value[x];
    int best =10e7;
    for(auto c: arr)
    {
        best= min(best,solve(x-c)+1);
    }
    value[x]=best;
    resolve[x]=true;
    return best;
}
int main()
{
    int n;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    arr[0]=1;
    int x=1;
    for(x; x<n and fact[x-1]*x<n; x++)fact[x]=fact[x-1]*x;
    int p= solve(n);
    cout<<p;
}
