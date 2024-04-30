//libraries
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//namespaces
using namespace __gnu_pbds;
using namespace std;

//templates

template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(k): Kth element in a Set (counting from zero).


/* TYPES  */
#define ll long long                   /*                   _                  */
#define pii pair<int, int>             /*                  (@)                 */
#define pll pair<long long, long long> /*              __  ,´                  */
#define vi vector<int>                 /*              \_\/                    */
#define vll vector<long long>          /*                ;                     */
#define mii map<int, int>              /*               )(                     */
#define si set<int>                    /*              /  \                    */
#define sll set<ll>                    /*__\_________\(    )___\_________\_____*/
#define spll set<pair<ll,ll>>          /*________\_____'--' _________\_________*/
#define sc set<char>                   /*____\_________      ____\_________\___*/
                                       /*_\________\______    _________\_______*/
                                       /*______\_________\__  _____\_________\_*/
                                       /*___\________\_______ _\_________\_____*/
//defines
#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
#define MOD 1000000007
#define PI  3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b)          { if (a<b) return a; return b; }
ll min(int a,ll b)          { if (a<b) return a; return b; }
ll max(ll a,int b)          { if (a>b) return a; return b; }
ll max(int a,ll b)          { if (a>b) return a; return b; }
ll gcd(ll a,ll b)           { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b)           { return a/gcd(a,b)*b; }
ll modpow(ll x,ll n, ll m)  { if(n==0)return 1%m; ll u=modpow(x,n/2,m);u=(u*u)%m;if(n%2==1)u=(u*x)%m;return u; }
ll modinv(ll x,ll m)        { return modpow(x,m-2,m); }
ll modneg(ll a,ll m)        { return m+(m%a); }
string to_upper(string a)   { for (size_t i=0;i<a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a)   { for (size_t i=0;i<a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a)            { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes()                  { cout<<"YES\n"; }
void no()                   { cout<<"NO\n"; }

struct  DSU
{
    size_t len;vll parent,size;
    DSU(size_t len_)             { len= len_;parent.resize(len);for(size_t x=0; x<len; x++)parent[x]=(ll)x;size.resize(len,1); }
    void make_set(ll v)          { parent[(size_t)v] = v; }
    ll find_set(ll v)            { if (v == parent[(size_t)v])return v;return parent[(size_t)v] = find_set(parent[(size_t)v]); }
    void union_sets(ll a, ll b)  { a = find_set(a);b = find_set(b);if (a != b) {if (size[(size_t)a] < size[(size_t)b])swap(a, b);
                                   parent[(size_t)b] = a;size[(size_t)a] += size[(size_t)b];} }
    ll size_of_set(ll a)         { return size[(size_t)find_set(a)];}
};

struct SegmentTree
{   vector<ll> tree;size_t len;
    SegmentTree()                   { len=0;}SegmentTree(size_t size_){len=1;for(; len<size_; len<<=1);tree.resize(2*len,0); }
    void construct(vector<ll> &nums){ for(size_t x=0; x<nums.size(); x++)tree[x+len]=nums[x];for(size_t x=len-1; x>=1; x--)tree[x]= tree[2*x]+tree[2*x+1]; }
    ll query(size_t l, size_t r){
        l += len; r +=len;
        ll s = 0;
        while (l <= r)
        {
            if (l%2 == 1) s += tree[l++];
            if (r%2 == 0) s += tree[r--];
            l /= 2; r /= 2;
        }
        return s;
    }
    void set(size_t position, ll value){
        position += len;
        tree[position] = value;
        for (position /= 2; position >= 1; position /= 2)
            tree[position] = tree[2*position]+tree[2*position+1];
    }
};

void precalc()
{

}

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    precalc();
    while(t--)
        solve();
}