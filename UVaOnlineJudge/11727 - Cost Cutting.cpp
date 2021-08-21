#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll cuenta=1;
    cin>>n;
    while(n--)
    {
        vector <ll> vect(3,0);
        for(auto &x: vect)
            cin>>x;
        sort(all(vect));
        cout<<"Case "<<cuenta<<": "<<vect[1]<<"\n";
        cuenta++;
    }
}

