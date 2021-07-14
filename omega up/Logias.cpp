#include <iostream>
using namespace std;

int main()
{
    long long int n,m,aux,aux2,aux3;
    cin>>n>>m;
    aux=n/m;
    aux3=n%m;
    aux2=((aux*(aux-1))/2)*(m-aux3);
    aux=((aux*(aux+1))/2)*(aux3);
    aux+=aux2;
    cout<<aux<<" ";
    aux=(n-(m-1));
    cout<<(aux*(aux-1))/2;

}
