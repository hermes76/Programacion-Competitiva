#include <iostream>
using namespace std;

int main()
{
    string cad;
    cin>>cad;
    cad+='$';
    int n= cad.length();
    pair<char,int> sufijo;
    for(int x=0; x<n; x++)
    {
        sufijo.first=cad[x];
        sufijo.second=x;
    }
    sort(sufijo,sufijo+n);

}
