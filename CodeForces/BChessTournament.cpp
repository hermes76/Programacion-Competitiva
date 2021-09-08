#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve()
{
    ll n;
    string cad;
    cin>>n>>cad;
    char arr[n][n];
    for(ll x=0; x<n; x++)
        for(ll y=0; y<n; y++)
        arr[x][y]='=';
        for(ll x=0; x<n; x++)
        arr[x][x]='X';
    bitset<50>bs;
    bs.reset();
    for(ll x=0; x<n; x++)
    {
        if(bs[x]==0)
        for(ll y=0; y<n; y++)
        {
            if(x==y)
                continue;
            if(arr[x][y]=='=')
            {
                if(cad[x]=='2')
                {
                    if(cad[y]=='2' && bs[x]==0)
                    {
                        arr[x][y]='+';
                        arr[y][x]='-';
                        bs[x]=1;
                    }
                    else
                    {
                        if(cad[y]=='2')
                            bs[y]=1;
                        arr[x][y]='-';
                        arr[y][x]='+';
                    }
                }
                else
                {
                    if(cad[y]=='2')
                    {
                        arr[x][y]='+';
                        arr[y][x]='-';
                    }
                }

            }
        }
    }
    for(ll x=0; x<n; x++)
    {
        if(cad[x]=='1')
        {
            bs[x]=1;
            for(ll y=0; y<n; y++)
            {
                if(arr[x][y]=='-')
                    bs[x]=0;
            }
        }
    }
    bool res=1;
    for(ll x=0; x<n; x++)
        res&=bs[x];
    if(res)
    {
        cout<<"YES"<<endl;
        for(ll x=0; x<n; x++)
        {
            for(ll y=0; y<n; y++)
            {
                cout<<arr[x][y];
            }
            cout<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)solve();
}

