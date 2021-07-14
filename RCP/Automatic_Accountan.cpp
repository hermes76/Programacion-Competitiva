#include <iostream>
#include <vector>
#include <algorithm>
#define o pair<int,int>
using namespace std;

int busqueda(int n,  vector < pair<int,o > >arr,int elemento)
{
    int inicio=0;
    int fin=n-1;
    int medio;
    while(inicio<=fin)
    {
        medio=(inicio+fin)/2;
        if(arr[medio].first==elemento)
        {
            return medio;
        }
        if(arr[medio].first>elemento)
        {
            fin=medio-1;
        }else if(arr[medio].first<elemento)
        {
            inicio=medio+1;
        }
    }
    return medio;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int res=0;
    int n,m;
    cin>>n;
    vector <pair<int,o>>ranuras (n);
    for(int x =0; x<n; x++)
    {
        cin>>ranuras[x].first;
        cin>>ranuras[x].second.first;
        ranuras[x].second.second=x;
    }
    sort(ranuras.begin(),ranuras.end());
    cin>>m;
    vector <pair<int,int>>monedas (m);
    for(int x =0; x<m; x++)
    {
        cin>>monedas[x].first;
        cin>>monedas[x].second;
    }
    for(int x=0; x<m; x++)
    {
        int y=busqueda(n,ranuras,monedas[x].first);
        if(y>0)
        {
            y--;
        }
        for(y; y<n; y++)
        {
            if(ranuras[y].first>=monedas[x].first && ranuras[y].second.first<=monedas[x].second)
            {
                break;
            }
        }
        cout<<ranuras[y].second.second<<endl;
        res+=ranuras[y].second.second+1;
    }
    cout<<res;
}