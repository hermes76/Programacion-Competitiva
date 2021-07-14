#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ideal[n];
    int apartamentos[n];
    for(int x =0; x<n; x++)
    {
        cin>>ideal[x];
    }
    for(int x =0; x<m; x++)
    {
        cin>>apartamentos[x];
    }
    sort(ideal,ideal+n);
    sort(apartamentos,apartamentos+m);
    int indice=0;
    int x=0;
    int cuenta=0;
    while(x<n and indice<m)
    {
        if(ideal[x]-k <=apartamentos[indice] && ideal[x]+k >=apartamentos[indice])
        {
            indice++;
            cuenta++;
            x++;
        }else if(ideal[x]-k>apartamentos[indice])
        {
            indice++;
        }else if(ideal[x]+k<apartamentos[indice])
        {
            x++;
        }
    }
    cout<<cuenta;
}
