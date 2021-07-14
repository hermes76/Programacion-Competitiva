#include <iostream>
#include <math.h>
using namespace std;

int solve(int s)
{
    float suma=0;
    int x=1;
    for(x; suma<s; x++){ suma+=1/(sqrt(x)+sqrt(x+1)); /*cout<<suma<<endl;*/}
    return x-1;
}
int main()
{
    int n,s;
    cin>>n;
    while(n--){cin>>s;cout<<solve(s)<<endl;}
}
