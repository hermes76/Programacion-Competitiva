
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
ll mini(ll a, ll b)
{
    if(a<b)
        return a;
    return b;
}
void preCalc()
{
    for(ll x=1; x<1e18; x<<=1)
        vll.push_back(x);
}
ll comp(string cad, string cad2)
{
    ll take=0;
    ll apuntPow=0;
    for(ll x=0; x<cad.length(); x++)
    {
        if(cad[x]==cad2[apuntPow])
        {
            take++;
            apuntPow++;
        }
    }
    return cad.length()-take+cad2.length()-apuntPow;
}
ll solve()
{
    ll n;
    ll res=11;
    cin>>n;
    string cad=to_string(n);

    for(ll x=0; x<vll.size(); x++)
        res=mini(res,comp(cad,to_string(vll[x])));
    return mini(res,cad.length()+1);
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
