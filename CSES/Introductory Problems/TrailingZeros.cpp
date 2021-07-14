#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int res=0;
    for(int x =5; x<=n; res+=n/x,x=x*5);
    printf("%d",res);
}
