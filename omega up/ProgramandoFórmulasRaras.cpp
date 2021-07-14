#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x,y,z;
    cin>>x>>y>>z;
    float res= (x+x*(y+pow(z,2)))/((x+M_PI)*(y+M_PI));
    cout<<res;
}