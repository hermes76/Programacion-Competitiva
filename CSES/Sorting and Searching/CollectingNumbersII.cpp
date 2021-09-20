#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve()
{
   ll n,m;
   cin>>n>>m;
   ll nums[n+1];
   ll positions[n];
   ll res=1;
   for(ll x=1; x<=n; x++)
   {
       cin>>nums[x];
       positions[nums[x]]=x;
   }

   for(ll x=1; x<n; x++)
        if(positions[x]>positions[x+1])
            res++;
    ll l,r;
    set<pair<ll,ll>> update_pairs;
    while(m--)
    {
        cin>>l>>r;
        if(nums[l]+1<=n)
            update_pairs.insert({nums[l], nums[l]+1});
        if(nums[l]-1>=1)
             update_pairs.insert({nums[l]-1,nums[l]});
        if(nums[r]+1<=n)
            update_pairs.insert({nums[r], nums[r]+1});
        if(nums[r]-1>=1)
             update_pairs.insert({nums[r]-1, nums[r]});
        for(auto x:update_pairs)
            res-= positions[x.first]>positions[x.second];
        swap(nums[l],nums[r]);
        positions[nums[l]]=l;
        positions[nums[r]]=r;
        for(auto x: update_pairs)
            res+=positions[x.first]>positions[x.second];
        cout<<res<<"\n";
        update_pairs.clear();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

