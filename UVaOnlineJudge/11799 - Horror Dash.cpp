
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve()
{

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll cuenta=1;
    cin>>n;
    while(n--)
    {
        ll m,res=0, input;
        cin>>m;
        for(ll x=0; x<m; x++)
        { cin>>input;
            res=max(res,input);
        }
        cout<<"Case "<<cuenta<<": "<<res<<endl;
        cuenta++;
    }
}
