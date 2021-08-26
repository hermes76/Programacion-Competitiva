
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
    ll k;
    cin>>k;
    ll cont=0;
    while(k)
    {
        cont++;
        while(cont%3==0 or cont%10 == 3)
            cont++;
        k--;
    }
    return cont;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)cout<<solve()<<endl;
}
