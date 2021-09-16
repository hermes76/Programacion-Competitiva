
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
    ll a,b;
    string cad;
    cin>>a>>b>>cad;
    ll l,r;
    l=0;
    r=cad.length()-1;
    for(; l<=r; l++, r--)
    {
        if(cad[l]=='?'&& cad[r]!='?')
            cad[l]=cad[r];
        else if(cad[r]=='?' && cad[l]!='?')
            cad[r]=cad[l];
        else if(cad[l]!= '?' && cad[r]!= '?' && cad[l]!= cad[r])
            return "-1";
    }
    l=0;
    r=cad.length();
    if(r%2==1 && cad[r/2]=='?')
    {
       if(a%2==1)
            cad[r/2]='0';
        else if(b%2==1)
            cad[r/2]='1';
        else return "-1";
    }
    r--;
     a-=count(all(cad),'0');
    b-=count(all(cad),'1');
    for(; l<r; l++,r--)
    {
       if(cad[l]=='?')
       {
           if(a>=2)
           {
               cad[l]='0';
               cad[r]='0';
               a-=2;
           }
            else if(b>=2)
            {
                cad[l]='1';
                cad[r]='1';
                b-=2;
            }
            else return "-1";
       }
    }
    if(a==0&& b==0)
    return cad;
    return "-1";
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
