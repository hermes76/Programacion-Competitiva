#include <iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    bool p=1;
    for(int x =0; x<a.length(); x++)if(a[x]!=a[a.length()-x-1])p=0;
    if(p==0)
        cout<<"NO";
        else cout<<"SI";
}
