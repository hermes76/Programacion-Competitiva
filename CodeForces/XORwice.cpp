#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b;
    int maximo;
    while(n--)
    {
        cin>>a>>b;
        maximo=max(a,b);
        cout<<(a^maximo)+(b^maximo)<<endl;
    }
}
