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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll mult=1;
    cin>>n;
    int arr[n];
    for(ll x=0; x<n; x++)
        cin>>arr[x];
    for(ll x=n-1; x>=0; x--)
        mult*=arr[x];
    for(ll x=0; x<n; x++)
        cout<<mult/(ll)arr[x]<<endl;
}
