#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
ll n;
void solve(ll pos1,ll pos2,bitset<36> bin)
{
    if(pos1>pos2)
    {
        for(ll x=0; x<n; x++)
            cout<<bin[x];
        cout<<"\n";
        return;
    }
    bin[pos1]=0;
    bin[pos2]=0;
    solve(pos1+1,pos2-1,bin);
    bin[pos1]=1;
    bin[pos2]=1;
    solve(pos1+1,pos2-1,bin);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    bitset<36> bin;
    solve(0,n-1,bin);
}

