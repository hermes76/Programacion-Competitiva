#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int Res=2;
   for(int x=1; x<n; x++,Res=2*Res,Res%=1000000007);
    cout<<Res;
}
