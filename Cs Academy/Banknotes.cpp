#include <bits/stdc++.h>
using namespace std;

#define ll long long int
bool isgood(ll k, ll a, ll b, ll s, ll n)
{
    if((s-((k*a)+(n-k)*b))>=0)
        return 1;
    return 0;
}
int banknotes(int A, int B, int S, int N) {
    int k=0;
    int l,r;
    l=-1;
    r=(N+1);
    if(A<B)
    {
        while(r>l+1)
        {
            k=(l+r)/2;
           if(isgood(k,A,B,S,N))
            r=k;
            else
            l=k;
        }
        if(r*A + (N-r)*B==S)
            return r;
        return -1;
    }else
    {
         while(r>l+1)
        {
            k=(l+r)/2;
           if(isgood(k,B,A,S,N))
            r=k;
            else
            l=k;
        }
        if((N-r)*A + r*B==S)
            return N-r;
        return -1;
    }
}

int main() {
    int A, B, S, N;
    cin >> A >> B >> S >> N;
    cout << banknotes(A, B, S, N) << "\n";
    return 0;
}
