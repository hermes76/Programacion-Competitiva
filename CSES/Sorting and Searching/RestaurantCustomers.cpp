#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct p
{
    int inicio,fin;
};
p arr[200000];
bool comp(p a, p b)
{
    if(a.inicio==b.inicio)
    {
        return a.fin>b.fin;
    }
    return a.inicio<b.inicio;
}
int res=0;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    int indice1=0,indice2=0;
    int suma=0;
    int res=0;
    for(int x=0; x<n; x++)
    {
        cin>>arr[x].inicio;
        cin>>arr[x].fin;
    }
    sort(arr,arr+n,comp);
    for(int x=0; x<n; x++)
    {
        cout<<arr[x].inicio<<" "<<arr[x].fin<<endl;
    }
    while(indice1<n)
    {
        if(arr[indice1].inicio<arr[indice2].fin)
        {
            suma++;
            indice1++;
        }else{
            suma--;
            indice2++;
        }
        res=max(res,suma);
    }
    cout<<res;
}
