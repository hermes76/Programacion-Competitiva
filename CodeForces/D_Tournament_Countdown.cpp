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
struct SegmentTree
{
    vector<ll> tree;
    ll len;
     SegmentTree()
    {
        len=0;
    }
    SegmentTree(ll size_)
    {
        len=1;
        for(; len<size_; len<<=1);
        tree.resize(2*len,0);

    }
    void construct(vector<ll> &nums)
    {
        for(ll x=0; x<nums.size(); x++)
            tree[x+len]=nums[x];
        for(ll x=len-1; x>=1; x--)
            tree[x]= tree[2*x]+tree[2*x+1];
    }
    ll query(ll l, ll r)
    {
        l += len; r += len;
        ll s = 0;
        while (l <= r)
        {
            if (l%2 == 1) s += tree[l++];
            if (r%2 == 0) s += tree[r--];
            l /= 2; r /= 2;
        }
    return s;
    }
    void remplace(ll position, ll new_value)
    {
        position += len;
        tree[position] = new_value;
        for (position /= 2; position >= 1; position /= 2)
        {
            tree[position] = tree[2*position]+tree[2*position+1];
        }
    }
};
ll compare(ll a,ll b)
{
    cout<<"? "<<a<<' '<<b<<endl;
    ll input;
    cin>>input;
    return input;
}
ll four(ll start, ll len,  map<pair<ll,ll>,ll> &winners)
{
    ll a,b,c,d;
    a=winners[{start,start+len-1}];
    b=winners[{start+len,start+len +len-1}];
    c=winners[{start+len+len,start+len*3-1}];
    d=winners[{start+len*3,start+len*4-1}];
    ll input=compare(a,d);
    ll res;
    if(input==1)
    {
        input=compare(a,c);
        if(input==1)res=a;
        else res=c;
    }
    else if(input==2)
    {
        input=compare(b,d);
        if(input==1)res=b;
        else res=d;
    }else if(input==0)
    {
        input=compare(b,c);
        if(input==1)res=b;
        else res=c;
    }
    else return -1;
    winners[{start,start+len*4-1}]=res;
    return 1;
}
void solve()
{
    ll n;
    cin>>n;
    map<pair<ll,ll>,ll> winners;
    for(ll x=1; x<=pow(2,n); x++)
        winners[{x,x}]=x;
    
    if(n==1)
    {
        cout<<"? "<<1<<' '<<2<<endl;
        ll a;
        cin>>a;
        if(a==2)
            winners[{1,pow(2,n)}]=2;
        else
            winners[{1,pow(2,n)}]=1;
    }
    else if(n==2)
    {
       if(four(1,1,winners)==-1)
        return;
    }
    else{
        ll limit= pow(2,n);
        ll y=4;

        for(y; y<=limit; y*=4)
        {
            for(ll x=1; x<pow(2,n); x=x+y)
            {
                if(four(x,y/4,winners)==-1)
                return;
            }
        }
        if(n%2==1)
        {
            ll a,b;
            a=winners[{1,pow(2,n)/2}];
            b= winners[{pow(2,n)/2+1, pow(2,n)}];
            cout<<"? "<<a<<' '<<b<<endl;
            ll input;
            cin>>input;
            if(input==1)
                winners[{1,pow(2,n)}]=a;
            else if(input==2)
                winners[{1,pow(2,n)}]=b;
            else return;
        }
    }
    fflush(stdout);
    cout<<"! "<<winners[{1,pow(2,n)}]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
    for(ll x=0; x<t; x++)
        solve();
}