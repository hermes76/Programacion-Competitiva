
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
    string cad;
    cin>>cad;
    char letra=cad.size()+'a'-1;
    ll indexL,indexR;
    indexL=0; indexR=cad.size()-1;
    while(indexL<=indexR && letra>='a')
    {
        if(cad[indexL]==letra)
            indexL++;
        else if(cad[indexR]==letra)
            indexR--;
        else return "NO";
        letra--;
    }
    return "YES";
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
