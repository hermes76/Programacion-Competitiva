#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;

ll solve()
{
    ll n,m;
    cin>>n>>m;
    vector <ll> vll;
    ll res=0;
    ll num;
    cin>>num;
    vll.push_back(num);
    for(ll x=1; x<m; x++)
    {
        cin>>num;
        auto it=lower_bound(all(vll),num);
        res+=distance(vll.begin(),it);
        vll.insert(it,num);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}

