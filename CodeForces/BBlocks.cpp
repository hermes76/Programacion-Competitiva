
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

void solve()
{
    ll n;
    string cadO;
    cin>>n>>cadO;
    string cad=cadO;
    vector<ll>res;
    bool finish;
    for(ll x=0; x<3; x++)
    {
        finish=1;
        for(ll y=0; y<n-1; y++)
        {
            if(cad[y]=='B')
            {
                res.push_back(y+1);
                cad[y]='W';
                if(cad[y+1]=='B')
                    cad[y+1]='W';
                else cad[y+1]='B';
            }
        }
        for(ll y=0; y<n; y++)
            if(cad[y]=='B')
                finish=0;
        if(finish)
        {
            cout<<res.size()<<endl;
            for(ll y=0; y<res.size(); y++)
                cout<<res[y]<<" ";
            return ;
        }
    }
    cad=cadO;
    res.clear();
    for(ll x=0; x<3; x++)
    {
        finish=1;
        for(ll y=0; y<n-1; y++)
        {
            if(cad[y]=='W')
            {
                res.push_back(y+1);
                cad[y]='B';
                if(cad[y+1]=='W')
                    cad[y+1]='B';
                else cad[y+1]='W';
            }
        }
        for(ll y=0; y<n; y++)
            if(cad[y]=='W')
                finish=0;
        if(finish)
        {
            cout<<res.size()<<endl;
            for(ll y=0; y<res.size(); y++)
                cout<<res[y]<<" ";
            return ;
        }
    }
    cout<<-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

