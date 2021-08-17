
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

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char cad;
    bool comillas=0;
    while(scanf("%c",&cad)!=EOF)
    {
        if(cad=='\"')
        {
            if(!comillas)
            {
                printf("``");
                comillas=1;
            }else
            {
                printf("''");
                comillas=0;
            }
        }else
         printf("%c",cad);
    }

}
