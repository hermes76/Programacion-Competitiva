#include <iostream>
#include <algorithm>  

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int cuenta=0;
    if(c<a and c<b)
    {
        cuenta++;
        swap(a,c);
    }else if( b<a and b<c)
    {
        cuenta++;
        swap(b,a);
    }
    if(c<b)
    {
        cuenta++;
    }
    cout<<cuenta;
}