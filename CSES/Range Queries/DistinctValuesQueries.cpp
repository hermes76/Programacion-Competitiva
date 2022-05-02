//libraries
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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

//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(k): Kth element in a Set (counting from zero).
*/

//typedefs
typedef long long ll;
typedef double dll;
typedef vector<ll> vll;

//defines
#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define MOD 1000000007
struct Query
{
    int l,r,order,block;
    bool operator < (Query &b)
    {
        if(block<b.block)
            return 1;
        else if(block>b.block)
            return 0;
        return r<b.r;
    }
};

int n,m;
int nums[200005];
int freq[200005];
int dist;
int l,r;
void addd(int &c)
{
    if(!freq[c])
        dist++;
    freq[c]++;
}
void eli(int &c)
{
    freq[c]--;
    if(!freq[c])
        dist--;
}
void do_operations(Query& q)
{
    while(l>q.l)
    {
        l--;
        addd(nums[l]);
    }
     while(r<q.r)
    {
         r++;
        addd(nums[r]);

    }
    while(l<q.l)
    {
        eli(nums[l]);
        l++;
    }

    while(r>q.r)
    {
        eli(nums[r]);
        r--;
    }
}
void solve()
{
    cin>>n>>m;
    map<int,int> compress;
    vector<Query> q(m);
    int next=1;
    int a;
    for(int x=0; x<n; x++)
    {
        cin>>nums[x];
        a= compress[nums[x]];
        if(a==0)
        {
            a=next;
            compress[nums[x]]=next++;
        }
        nums[x]=a;
    }
    int b;
    for(int x=0; x<m; x++)
    {
        cin>>a>>b;
        q[x].l=a-1;
        q[x].r=b-1;
        q[x].order=x;
        q[x].block=a/555;
    }
    vector<int > ans(m);
    sort(all(q));
    r=l = q[0].l;
    dist=1;
    freq[nums[l]]++;
    for(Query & qr :q)
    {
        do_operations(qr);
        ans[qr.order]=dist;
    }
    for(int x: ans)
        cout<<x<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //while()
        solve();
}
