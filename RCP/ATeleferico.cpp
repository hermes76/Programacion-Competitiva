#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float n,m;
    int res1;
    float res;
    cin>>n>>m;
    res=m/(n-1);
    res1=res;
    if((float)res1<res)
        res1++;
    cout<<res1;
}
