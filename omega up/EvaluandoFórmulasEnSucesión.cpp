#include <iostream>
using namespace std;


int main()
{
    float x;
    cin>>x;
    float y,z;
    y = (x+5)/(2*(x+1));
    z=(y*y+x*(x-2*y))/(x*y);
    cout<<z;
}