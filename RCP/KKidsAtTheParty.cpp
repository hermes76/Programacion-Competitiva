#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
void solve()
{
    string cad;
    cin>>cad;
    bitset<6>bs;
        bs.reset();
    for(ll x=0; x<=8; x+=2)
        if(cad[cad.length()-1]==char(x+48))
        bs[1]=1;
    if(cad[cad.length()-1]=='0' or cad[cad.length()-1]=='5')
        bs[4]=1;
        ll num=0;
        for(ll x=0; x<cad.length(); x++)
            num+=cad[x]-'0';
    if(num%3==0)
        bs[2]=1;
    if(cad.length()>=2)
    {
       string numero="  ";
       numero[0]=cad[cad.length()-2];
       numero[1]=cad[cad.length()-1];
        num=stoi(numero);
        if(num%4==0)
        bs[3]=1;
    }
    else{
         string numero=" ";
       numero[0]=cad[cad.length()-1];
        num=stoi(numero);
        if(num%4==0)
        bs[3]=1;
    }
    if(bs[1]==1 && bs[2]==1)
        bs[5]=1;
    vll.clear();
    for(ll x=2; x<=6; x++)
        if(bs[x-1])
            vll.push_back(x);
    if(!vll.empty())
    {
        ll x=0;
        for(x; x<vll.size()-1; x++)
            cout<<vll[x]<<" ";
        cout<<vll[x]<<endl;
    }else cout<<-1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--)
        solve();
}

