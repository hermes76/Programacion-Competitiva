#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dias=0;
    while(n*(1<<(dias))%11!=1)
    {
        dias++;
    }
    cout<<dias<<" "<<n*(1<<dias);
}
