
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
ll solve()
{
    int n; cin>>n;
    ll cuenta=0;
    int arr[n];
    for(int x=0; x<n; x++)
        cin>>arr[x];


        sort(arr,arr+n,greater<int>());
    for(int x=0; x<n; x++)
        for(int y=x+1; y<n; y++)
            if(gcd(arr[x],2*arr[y])>1)
                cuenta++;

    return cuenta;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        cout<<solve()<<"\n";
    }
}
