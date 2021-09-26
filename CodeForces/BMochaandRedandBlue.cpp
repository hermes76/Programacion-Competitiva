
#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;*/

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double dll;

vector <ll> vll;

string solve()
{
    ll n;
    cin>>n;
    string cad;
    cin>>cad;
    if(n==1)
        if(cad[0]=='?')
            return "B";
    for(ll x=0; x<n; x++)
    {
        if(cad[x]=='R')
        {
            ll aux=x;
            x--;
            char cha='B';
            while(x>=0 && cad[x]=='?')
            {
                cad[x]=cha;
                if(cha=='B')
                    cha='R';
                else cha='B';
                x--;
            }
            x=aux;
        }else if(cad[x]=='B')
        {
            ll aux=x;
            x--;
            char cha='R';
            while(x>=0 && cad[x]=='?')
            {
                cad[x]=cha;
                if(cha=='B')
                    cha='R';
                else cha='B';
                x--;
            }
            x=aux;
        }

    }
    for(ll x=0; x<n; x++)
    {
        if(cad[x]=='?')
        {
            if(cad[x-1]=='R')
                cad[x]='B';
            else cad[x]='R';
        }
    }
    return cad;
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

