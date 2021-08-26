
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
void preCalc()
{
    vll.push_back(1);
    ll cont=1;
    for(ll x=1; cont+x<=1e9; x+=2)
    {
        cont+=x;
        vll.push_back(cont);
    }
}
void solve()
{
    ll k;
    cin>>k;
    ll x=0;
    ll row,col;
    for(x; x<vll.size() && vll[x]<=k; x++);
    x--;
    if(k<=vll[x]+x-1)
    {
        col=x;
        row=k-vll[x];
    }else{
        row=x;
        col=x-(k-(vll[x]+x));
    }
    row++;
    col++;
    cout<<row<<" "<<col<<"\n";


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    preCalc();
    cin>>t;
    while(t--)
        solve();
}
