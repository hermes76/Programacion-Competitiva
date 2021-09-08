#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve()
{
    ll n;
    cin>>n;
    string cad;
    cin>>cad;
    for(ll x=0; x<n; x++)
    {
        ll A=0;
        ll B=0;
        for(ll y=x; y<n; y++)
        {
            if(cad[y]=='a')
                A++;
            else B++;
            if(A==B)
            {
                cout<<x+1<<" "<<y+1<<endl;
                return ;
            }

        }

    }
    cout<<-1<<" "<<-1<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();
}

