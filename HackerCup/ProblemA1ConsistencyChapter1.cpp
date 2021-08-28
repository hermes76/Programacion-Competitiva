#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;
unordered_map <char,bool> mapa;
ofstream out("Output.txt");
ifstream in("a.txt");
ll solve(string cad)
{
    ll res=0;
    ll vocales=0;
    ll arr[27];
    ll maximoVocal=0;
    ll maximo=0;
    ll maximoConsonante=0;
    ll consonantes;
    for(ll x=0; x<27; x++)arr[x]=0;
    for(ll x=0; x<cad.length(); x++)
    {
        if(mapa[cad[x]])vocales++;
        arr[cad[x]-'A']++;
    }
    for(ll x=0; x<cad.length(); x++)
        if(mapa[cad[x]])
            maximoVocal=max(maximoVocal,arr[cad[x]-'A']);
        else
            maximoConsonante=max(maximoConsonante,arr[cad[x]-'A']);
    consonantes=cad.length()-vocales;
    return min( (vocales-maximoVocal)*2+consonantes,(consonantes-maximoConsonante)*2+vocales);


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll x='A'; x<'Z'; x++)
        mapa[x]=0;
    mapa['A']=1;
    mapa['E']=1;
    mapa['I']=1;
    mapa['O']=1;
    mapa['U']=1;
    ll t;
    string cad;
    in>>t;
    cout<<t;
    ll cont=1;
    while(t--)
    {
        in>>cad;
        out<<"Case #"<<cont<<": "<<solve(cad)<<"\n";
        cont++;
    }
    in.close();
    out.close();
}

