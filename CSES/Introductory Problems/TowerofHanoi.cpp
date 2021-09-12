#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve(ll discos,ll t1,ll t2,ll t3)
{
    if(discos==1)
    {
        cout<<t1<<" "<<t3<<endl;
    }
    else{
        solve(discos-1,t1,t3,t2);
        cout<<t1<<" "<<t3<<endl;
        solve(discos-1,t2,t1,t3);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(n,1,2,3);
}

