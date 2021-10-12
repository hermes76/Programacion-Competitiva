//libraries
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//namespaces
//using namespace __gnu_pbds;
using namespace std;

//templates
/*
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

*/

//typedefs
typedef long long ll;
typedef double dll;
typedef vector<ll> vll;

//defines
#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007


void solve()
{
    ll n;
    cin>>n;
    bool students[n][5];
    ll group1,group2,neither;
    for(ll x=0; x<n; x++)
        for(ll y=0; y<5; y++)
        cin>>students[x][y];

    if(n%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    for(ll x=0; x<5; x++)
    {
        for(ll y=0; y<5; y++)
        {
            if(x==y)
                continue;
            group1=0;
            group2=0;
            neither=0;
            for(ll z=0; z<n; z++)
            {
                if(students[z][x] == 1 && students[z][y]==0)
                    group1++;
                if(students[z][y] == 1 && students[z][x]==0)
                    group2++;
                else if(students[z][x] ==0 && students[z][y] ==0)
                    neither++;

            }
            if(neither==0 && group1<=n/2 && group2<=n/2)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    //t=1;
    cin>>t;
    while(t--)
        solve();
}

