
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
void Power(ll k)
{
    if(k==1)
    {
        cout<<"2";
        return;
    }

    if(k%2==1)
    {
        cout<<"(2*";
        Power(k-1);
        cout<<")";
    }
    else
    {
        cout<<"(";
        Power(k/2);
        cout<<")^2";
    }

}
void solve()
{
    ll n;
    cin>>n;
    Power(n);
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)solve();
}
