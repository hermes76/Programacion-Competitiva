#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b and b==c and a==c)
    {
        cout<<"equilatero";
    }else if (a!=b and a!=c and b!=c)
    {
        cout<<"escaleno";
    }else{
        cout<<"isosceles";
    }
}