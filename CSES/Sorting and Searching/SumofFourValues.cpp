
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve(ll n,ll target, pair<ll,ll> arr[])
{
    ll indiceA;
    ll indiceB;
    ll suma;
    sort(arr,arr+n);
    for(ll x=0; x<n; x++)
    {

        for(ll y=x+1; y<n-2; y++)
        {
            indiceA=y+1;
            indiceB=n-1;
            while(indiceA<indiceB)
            {
                suma=arr[x].first+arr[y].first+arr[indiceA].first+arr[indiceB].first;
                if(suma<target)
                    indiceA++;
                else if(suma>target)
                    indiceB--;
                else
                {
                    cout<<arr[x].second+1<<" "<<arr[y].second+1<<" "<<arr[indiceA].second+1<<" "<<arr[indiceB].second+1;
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,target;
    cin>>n>>target;
    pair<ll,ll> arr[n];
    for(ll x=0; x<n; x++)
    {
        cin>>arr[x].first;
        arr[x].second=x;
    }
    solve(n,target,arr);
}
