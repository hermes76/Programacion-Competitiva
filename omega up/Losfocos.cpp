#include <iostream>
using namespace std;

int main()
{
    int n;
    int solve=3;
    int pasado=1;
    cin>>n;
    for(int x=1; x<n; x+=solve,solve+=2)cout<<x<<"\n";
}
