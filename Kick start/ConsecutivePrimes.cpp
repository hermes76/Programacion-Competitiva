#include <iostream>
#include <vector>
#define ll long long int
#define MAX 100000
using namespace std;
ll sieve[100009];
vector <ll> primes;
ll solve(ll z)
{
    ll x;
    for(x=1; x<primes.size(); x++)
        if(primes[x-1]*primes[x]>z)
            return primes[x-2]*primes[x-1];

}
int main()
{
    ll t,z;
    cin>>t;
    for (ll x = 2; x <=MAX; x++)
    {
        if (sieve[x]) continue;
        for (ll u = 2*x; u <= MAX; u += x)
        {
            sieve[u] = x;
        }
    }
    for(ll x=2; x<MAX; x++)
        if(!sieve[x])primes.push_back(x);
    for(ll x=1; x<=t; x++)
    {
        cin>>z;
        cout<<"Case #"<<x<<": "<<solve(z)<<"\n";
    }

}
