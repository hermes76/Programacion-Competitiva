#include <iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    char p;
    cin>>p;
    int cuenta=0;
    for(int x =0; x<a.length(); x++)if(p==a[x])cuenta++;
    cout<<cuenta;
}
