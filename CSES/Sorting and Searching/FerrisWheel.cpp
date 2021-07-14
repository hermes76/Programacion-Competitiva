#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int peso;
    cin>>n;
    cin>>peso;
    int ninos[n];
    int x=0;
    int y=n-1;
    int cuenta=0;
    for(int x =0; x<n; x++)
    {
        cin>>ninos[x];
    }
    sort(ninos,ninos+n);
    for(x,y; x<=y; y--)
    {
        if(ninos[x]+ninos[y]<=peso)
        {
            x++;
        }
        cuenta++;
    }
    cout<<cuenta;

}
