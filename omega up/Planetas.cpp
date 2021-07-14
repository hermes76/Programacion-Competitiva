
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
dll planetas[1000];
bool isgood(int n, dll k)
{
    dll suma=0;
    for(int x=0; x<n; x++)
        suma+=1/(planetas[x]-k);
    if(suma<0)
        return 1;
    return 0;
}
dll solve(int n, dll low, dll up)
{
    dll k;
    int veces=25;
    while(veces--)
    {
        k=(low+up)/2;
       // printf("%.3f\n",k);
        if(isgood(n,k))
            low=k;
        else up=k;
    }
    return low;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int x=0; x<n; x++)
    {
        scanf("%lf",&planetas[x]);
    }
    printf("%d\n",n-1);
    sort(planetas,planetas + n);
    for(int x=1; x<n; x++)
    {
        printf("%.3f ", solve(n,planetas[x-1],planetas[x]));
    }
}
