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
   string cad;
   cin>>cad;
   ll res=0;
   vector <char> cadena;
   vector <char>::iterator it;
   for(ll x=0; x<cad.length(); x++)
    cadena.push_back(cad[x]);

   it=unique(all(cadena));
    cadena.resize(distance(cadena.begin(),it));

    for(ll x=0; x<cadena.size(); x++)
        if(cadena[x]=='0')
            res++;

    if(res<2)
        return res;
    return 2;



}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
}

