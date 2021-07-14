
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
char cad[20];
char res[20];
void solve(int n, int k,int cont, int pos){
    if(cont>=k)
    {
       for(int x=0; x<k; x++)
            cout<<res[x];
       cout<<'\n';
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
    ll n,k;
    cin>>n>>k;
    for(int x=0; x<n; x++)cin>>cad[x];
    sort(cad,cad+n);
    solve(n,k,0,0);
}
