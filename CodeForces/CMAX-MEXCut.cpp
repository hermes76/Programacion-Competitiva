
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
ll solveA(string s)
{
    ll res= count(all(s),'0');
    bool A,B;
    A=B=0;
        for(ll x=0; x<s.length(); x++)
        {
            if(s[x]=='0')A=1;
            if(s[x]=='1')B=1;
            if(A&&B)
            {
                ++res;
                A=0;
                B=0;
            }
        }
        return res;
}
ll solve()
{
    ll n;
    string cad1,cad2;
    cin>>n>>cad1>>cad2;
    ll res=0;
    string s="";
    for(ll x=0; x<n; x++)
    {
        if(cad1[x]!=cad2[x])
        {
            res+=2 + solveA(s);
            s="";
        }
        else s+=cad1[x];
    }
    return res+solveA(s);

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
