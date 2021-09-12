#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
ll solve()
{
    ll n;
    in>>n;
    string cad;
    in>>cad;
    vector <char> chars;
    vector <char>::iterator it;
    for(ll x=0; x<cad.length(); x++)
        if(cad[x]!='F')
            chars.push_back(cad[x]);
    it=unique(all(chars));
    chars.resize(distance(chars.begin(),it));
    if(chars.size()==0)
        return 0;
    return chars.size()-1;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    in>>t;
    for(ll x=1; x<=t; x++)
        out<<"Case #"<<x<<": "<<solve()<<"\n";
    in.close();
    out.close();
}

