#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,b,h,w;
    while(scanf("%d %d %d %d",&n,&b,&h,&w)!= EOF)
    {
        int precio;
        int costo=INF;
        for(int x=0; x<h; x++)
        {
            int arr[w];
            scanf("%d",&precio);
            for(int x=0; x<w; x++)scanf("%d",&arr[x]);
            for(int x=0; x<w; x++)
            {

                if(arr[x]>=n && precio*n<=b)
                {
                    costo=min(costo,precio*n);
                }
            }

        }
        if(costo==INF)
            printf("stay home");
        else printf("%d",costo);
        printf("\n");
    }
}
