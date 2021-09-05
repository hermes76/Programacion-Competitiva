
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
    ll xA,yA,xB,yB,xF,yF;
    cin>>xA>>yA>>xB>>yB>>xF>>yF;
    ll distX=abs(xA-xB);
    ll distY=abs(yA-yB);
    if((xF== xA && xF == xB && min(yA,yB)<= yF && max(yA,yB)>=yF)||(yF== yA && yF == yB && min(xA,xB)<= xF && max(xA,xB)>=xF))
        return distX+distY+2;
    return distX+distY;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    string cad;
    while(t--)
    {
        getline(cin,cad);
        cout<<solve()<<endl;
    }
}
