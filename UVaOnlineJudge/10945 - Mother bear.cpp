
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve(string cad)
{
    for(ll x=0, y =cad.length()-1; x<=y;)
    {
        while(cad[x]<'A')
            x++;
        while(cad[y]<'A')
            y--;
        if(x>y)
            break;
        if(toupper(cad[x])!=toupper(cad[y]))
        {
            cout<<"Uh oh..\n";
            return ;
        }
        x++;
        y--;
    }
    cout<<"You won't be eaten!\n";
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string cad;
    do
    {
        getline(cin,cad);
        if(cad=="DONE")
            break;
        solve(cad);
    }while(1);
}
