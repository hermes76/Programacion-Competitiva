#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pelicula
{
    int x,y;
};
bool comp(pelicula a, pelicula b)
{
    return a.x<b.x;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<pelicula> vect;
    int n,m;
    int res=1;
    cin>>n>>m;
    pelicula arr[n];
    for(int x =0; x<n; x++){cin>>arr[x].x; cin>>arr[x].y;}
    sort(arr,arr+n,comp);
    pelicula mejor=arr[0];
    vect.push_back(mejor);
    int indice=0;
    for(int x =1; x<n; x++)
    {
        if(vect[indice].y<=arr[x].x)
        {
            indice++;
        }
        if(arr[x].x>mejor.x and arr[x].x<mejor.y and arr[x].y>mejor.x and arr[x].y<=mejor.y)
        {
            mejor=arr[x];
            vect.pop_back();
            vect.push_back(mejor);
        }
        else{
            if(vect.size()-indice<m){vect.push_back(arr[x]);res++;}
        }
    }
    cout<<res;
}
