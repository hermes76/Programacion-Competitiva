
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
    bitset<26>bs;
    char leter;
    bs.reset();
    ll n;
    cin>>n;
    string cad;
    cin>>cad;
    ll x=0;
    bool a;
   while(x<n)
   {
       leter=cad[x];
       a=0;
       while(x<n && cad[x]==leter)
       {
           a=1;
            x++;
       }
       if(bs[leter-'A']==1)
        return "NO";
       bs[leter-'A']=1;
       if(a==0)
            x++;
   }
    return "YES";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    while(n--)cout<<solve()<<endl;
}
