
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

void solve()
{
    ll n;
    cin>>n;

    vector<ll> office;
    vector<ll> ans;
    set<ll> entrances;
    set<ll> employes_registred;
    set<ll>:: iterator it;
    ll events=0;

    office.resize(n);
    for(ll x=0; x<n; x++)
        cin>>office[x];

    if(n%2==1)
    {
        cout<<"-1";
        return;
    }

    for(ll x=0; x<n; x++)
    {
        if(office[x]>0)
        {
            it=employes_registred.find(office[x]);
            if(it!=employes_registred.end())
            {
                cout<<"-1";
                return;
            }
            entrances.insert(office[x]);
            employes_registred.insert(office[x]);
            events++;
        }
        else{
            if(entrances.empty())
            {
                cout<<"-1";
                return;
            }
            it=entrances.find(office[x]*-1);
            if(it==entrances.end())
            {
                cout<<"-1";
                return;
            }
            entrances.erase(it);
            events++;
        }
        if(entrances.empty())
        {
            ans.push_back(events);
            employes_registred.clear();
            events=0;
        }
    }

    if(!entrances.empty())
    {
        cout<<"-1";
        return;
    }
    cout<<ans.size()<<endl;

    for(auto x:ans)
        cout<<x<<" ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

