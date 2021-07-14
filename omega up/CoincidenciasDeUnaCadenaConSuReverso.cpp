#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a;
    getline(cin,a);
    int co=0;
    int tam=a.length();
    for(int x =0; x<tam; x++)
    {
        if(tolower(a[x])==tolower(a[tam-x-1]))
        {
            co++;
        }
    }
    cout<<co;
}