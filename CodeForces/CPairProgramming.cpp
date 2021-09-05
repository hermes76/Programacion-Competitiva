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
    ll n,m,o;
    cin>>n>>m>>o;
    ll pol[m];
    ll mon[o];
    for(ll x=0; x<m; x++)cin>>pol[x];
    for(ll x=0; x<o; x++)cin>>mon[x];
    vector <ll> vect;
    ll indexP=0, indexM=0;
    while(indexP<m || indexM<o)
    {
        if(indexP<m && pol[indexP]==0)
        {
            vect.push_back(0);
            n+=1;
            indexP++;
        }
        else if(indexM<o && mon[indexM]==0)
        {
             vect.push_back(0);
            n+=1;
            indexM++;
        }
        else if(indexP<m&&pol[indexP]<=n)
        {
            vect.push_back(pol[indexP]);
                indexP++;
        }
        else if(indexM<o && mon[indexM]<=n)
        {
            vect.push_back(mon[indexM]);
            indexM++;
        }
        else{
            cout<<-1<<endl;
            return;
        }

    }
    for(auto x:vect)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--)
        solve();
}

