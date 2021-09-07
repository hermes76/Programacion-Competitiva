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
    string res="NO";
    if(cad[0]=='2' && cad[1]=='0' && cad[2]=='2' && cad[3]=='0')
        res="YES";
     if(cad[0]=='2' && cad[1]=='0' && cad[2]=='2' && cad[n-1]=='0')
        res="YES";
        if(cad[0]=='2' && cad[1]=='0' && cad[n-2]=='2' && cad[n-1]=='0')
        res="YES";
        if(cad[0]=='2' && cad[n-3]=='0' && cad[n-2]=='2' && cad[n-1]=='0')
        res="YES";
        if(cad[n-4]=='2' && cad[n-3]=='0' && cad[n-2]=='2' && cad[n-1]=='0')
        res="YES";
        return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)cout<<solve()<<"\n";
}

