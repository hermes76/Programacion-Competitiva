#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

string solve()
{
    ll n;
    cin>>n;
    string cad;
    cin>>cad;
    string res;
    for(ll x=0; x<n; x++)
    {
        if(cad[x]=='L')
            res+='L';
            else if(cad[x]=='R')
                res+='R';
        else if(cad[x]=='U')
            res+='D';
        else if(cad[x]=='D')
            res+='U';
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)cout<<solve()<<endl;
}

