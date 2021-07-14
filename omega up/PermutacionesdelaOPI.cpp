
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
vector <string> vs;
char cad[20];
char res[20];
bool isgood(string aux,ll n, ll k)
{
    if(k<n)
        if(aux<vs[k])
            return 1;
    return 0;
}
void solve(int n, int k,int cont, int pos){
    if(cont>=k)
    {
        string aux;
       for(int x=0; x<k; x++)
            aux+=res[x];
        vs.push_back(aux);
    }
    else
    {
        for(int x=pos; x<n; x++)
        {
            res[cont]=cad[x];
            solve(n,k,cont+1,x+1);
        }

    }
}
int main()
{
    ll n;
    cin>>n;
    string subconjunto;
    string cadena;
    cin>>cadena;
    for(int x=0; x<cadena.length(); x++)
        cad[x]=cadena[x];
    sort(cad,cad+n);
    solve(n,k,0,0);
    sort(vs.begin(),vs.end());
    for(int x=0; x<n; x++)
    {
        cin>>subconjunto;
        ll k=-1;
        for(int x=n/2; x>0; x/=2)
            while(isgood(subconjunto,n,k+x))k+=x;
            k++;
        cout<<k<<'\n';
    }
}

