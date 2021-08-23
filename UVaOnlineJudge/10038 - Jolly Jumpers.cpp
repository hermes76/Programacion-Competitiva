#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define l long
#define ll l l int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

string solve(l n,l arr[])
{
    bitset<1000000>bs;
    bs.reset();
    for(l x=1; x<n; x++)
    {
        if(bs[abs(arr[x-1]-arr[x])]==0)
            bs[abs(arr[x-1]-arr[x])]=1;
        else
            return "Not jolly";
    }
    for(l x=1; x<n; x++)
        if(bs[x]==0)
            return "Not jolly";
    return "Jolly";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    l n;
    while(scanf("%ld",&n)!=EOF)
    {
        l arr[n];
        for(l x=0; x<n; x++)scanf("%ld",&arr[x]);
        cout<<solve(n,arr)<<"\n";
    }
}

