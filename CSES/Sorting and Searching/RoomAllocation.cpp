
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

   vector<tuple<ll,ll,ll>> customer(n);
   vector<ll> ans(n);
    set<pair<ll,ll>> rooms;
    ll necesary_rooms=1;

    for(ll x=0; x<n; x++)
    {
        ll a,b;
        cin>>a>>b;
        customer[x]={a,b,x};
    }

    sort(all(customer));

    rooms.insert({get<1>(customer[0]),get<2>(customer[0])});
    ans[get<2>(customer[0])]=1;

   for(ll x=1; x<n; x++)
   {
       ll room=0;
       if(!rooms.empty() && get<0>(*rooms.begin()) < get<0>(customer[x]) )
       {
          // cout<<get<0>(*rooms.begin())<<" "<<get<1>(customer[x])<<endl;
           room = ans[get<1>(*rooms.begin())];
           rooms.erase(rooms.begin());
       }
       rooms.insert({get<1>(customer[x]), get<2>(customer[x])});
       if(rooms.size()>necesary_rooms)
            necesary_rooms=rooms.size();

       if(room==0)
            room=rooms.size();
        ans[get<2>(customer[x])]=room;
   }
    cout<<necesary_rooms<<endl;

    for(auto x: ans)
        cout<<x<<" ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

