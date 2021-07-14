#include <iostream>
using namespace std;
long long gdc(int a, int b)
{
    if(b==0)
        return a;
    return gdc(b,a%b);
}
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    n--;
    int paradas=n/a+n/b;
    paradas-=n/((a*b)/gdc(a,b));
    cout<<paradas<<endl;
}
