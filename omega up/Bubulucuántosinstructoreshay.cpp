#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int cuenta=0;
    for(int x =0; x<a.length(); x++)if(tolower(a[x])==tolower(a[a.length()-1-x]))cuenta++;
    cout<<cuenta;
}
