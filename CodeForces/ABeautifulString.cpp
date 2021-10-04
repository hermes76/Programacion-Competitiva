
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
    string cad;
    cin>>cad;
    string res;
    for(ll x=1;x<cad.length()-1; x++)
    {
        if(cad[x]== '?')
        for(ll y='a'; y<='c'; y++)
        {
            if(cad[x-1]!= y && y!= cad[x+1])
            {
                cad[x]=y;
                break;
            }
        }
    }
    if(cad[0]=='?' && cad.length()==1)
        cad[0]='a';
    else if(cad[0]== '?' && cad.length()>1)
    {
        if(cad[1]=='b')
            cad[0]='a';
        else cad[0]='b';
    }
    ll len=cad.length();
    if(cad[len-1]== '?' && len>1)
    {
        if(cad[len-2]=='b')
            cad[len-1]='a';
        else cad[len-1]='b';
    }
    for(ll x=1; x<len; x++)
        if(cad[x-1]== cad[x])
            return "-1";

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

