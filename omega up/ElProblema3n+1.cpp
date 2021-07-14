#include <iostream>
#define MAX 450000
using namespace std;

int dp[450001];
int rec(long long int n)
{
    int aux;
    if(n<MAX and n>0)
        if(dp[n]!=0)
        return dp[n];
    if(n%2==0)n/=2;
    else n=n*3+1;
    aux=rec(n);
    if(n>0 and n<MAX)
        dp[n]=aux;
    return aux+1;

}
int main()
{
    long long int m,n;
    cin>>m>>n;
    dp[1]=1;
    dp[2]=2;
    int solucion=0;
    while(n!=m-1)
    {
        solucion=max(solucion,rec(n));
        n--;
    }cout<<solucion;
}
