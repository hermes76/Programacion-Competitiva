
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> primes;
void preCalc()
{
    bitset<1000003>bs;
    bs.reset();
    for(ll x=2; x<=1000000; x++)
        if(bs[x]==0)
        {
            for(ll y=x*2; y<=1000000; y+=x)
                bs[y]=1;
            primes.push_back(x);
        }
}
ll solve()
{
    ll n,m;
    vector <ll>::iterator it1,it2;
    cin>>n>>m;
    it1=lower_bound(all(primes),min(n,m));
    it2=upper_bound(all(primes),max(n,m));
   return (it2-it1);


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    preCalc();
    ll t;
    cin>>t;
    while(t--)cout<<solve()<<endl;
}
