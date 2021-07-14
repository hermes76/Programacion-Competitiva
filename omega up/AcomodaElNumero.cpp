#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int busqueda;
    int m;
    int solve=0;
    cin>>n>>busqueda;
    n--;
    while(n--)
    {
        cin>>m;
        if(busqueda>m)solve++;
    }
    cout<<solve;
}
