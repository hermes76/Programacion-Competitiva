
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

void solve(int H,int U , int D, int F)
{
    int days=1;
    float factor=(float)U*F/100;
    float distance=U;
    float pos=0;
    while(pos>=0 && pos< H)
    {
        pos+=distance;
        if(pos>H)
            break;
        pos-=D;
        if(distance>0)
            distance-=factor;
        if(pos<0)
            break;
        days++;

    }
    if(pos>=H)
        printf("success on day %d\n",days);
    else
        printf("failure on day %d\n",days);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int H,U,D,F;
    while(scanf("%d %d %d %d",&H, &U, &D, &F), H!=0)
    {
        solve(H,U,D,F);
    }
}
