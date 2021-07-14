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


ll solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    ll upvotes =0, downvotes=0;
    for(ll x=0; x<n; x++)
        cin>>arr[x];
    for(ll x=0; x<n; x++)
        if(arr[x]==1)
            upvotes++;
        else if(arr[x]==2)
            downvotes++;
        else upvotes++;

    return upvotes;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<"\n";
}
