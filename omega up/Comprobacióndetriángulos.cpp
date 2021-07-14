#include <iostream>
using namespace std;

int main()
{
    long long int a,b,c;
    cin>>a>>b>>c;
    if(a<b+c & b<a+c & c<a+b)
        cout<<"SI";
    else
        cout<<"NO";
}
