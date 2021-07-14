#include <iostream>
#define ll long long int
using namespace std;
bool isgood(ll k, ll N,ll M, ll X, ll Y)
{
    ll caramelos=(Y*(N-k))+M;
    if(k*X <= caramelos)
     return 1;
    return 0;
}
int main() {
    ll N,M,X,Y;
    cin>>N>>M>>X>>Y;
    ll k=0;
    ll l, r;
    r=N+1;
    l=-1;
    /*for(ll x=1e9/2; x>=1; x/=2)
    {
        //cout<<k<<endl;
        while(isgood(k+x,N,M,X,Y))k+=x;
    }*/
    while(r>l+1)
    {
        k=(r+l)/2;
        if(!isgood(k,N,M,X,Y))
          r=k;
        else l=k;
    }
    cout<<l;
    return 0;
}
