#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
struct elementos
{
    char car;
    int pos;
};
bool comp(elementos a, elementos b)
{
    if(a.car<b.car)
        return 1;
    else if(a.car== b.car)
        if(a.pos<b.pos)
            return 1;
    return 0;
}
elementos orden[1000001];
bool islowergood(int len,int k, char bus)
{
    if(k<len)
        if(orden[k].car<bus)
            return 1;
    return 0;
}
bool isuppergood(int len,int k, char bus)
{
    if(k<len)
        if(orden[k].car<=bus)
            return 1;
    return 0;
}
bool isgoodness(int len, int k, int abajo, int arriba)
{
    if(k<=len)
        if(orden[k].pos<arriba)
            return 1;
    return 0;
}
ll solve(int len, int abajo, int arriba, char bus)
{
    int lower=-1;
    for(int x=len/2; x>0; x/=2)
        while(islowergood(len,lower+x, bus))
               lower+=x;
    lower++;
    if(orden[lower].car!= bus)
        return 0;
    ll upper=0;
    for(int x=len/2; x>0; x/=2)
        while(isuppergood(len,upper+x,bus))upper+=x;
    ll res=lower;
   for(int x=(lower+upper)/2; x>0; x/=2)
   {
     //  cout<<"X "<<x<<endl;
      // cout<<" "<<x<<" "<<abajo<<" "<<orden[x].pos<<" "<<arriba<<endl;
      while(isgoodness(upper, res+x, abajo, arriba))
      {
          res+=x;
         // cout<<"res "<<res<<endl;
      }
   }
    if(orden[res].pos>= abajo and orden[res].pos< arriba)
            return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string cad;
    char car;
    int abajo, arriba;
    int n;
    cin>>cad>>n;
    for(int x=0; x<cad.length(); x++)
    {
        orden[x].car = cad[x];
        orden[x].pos=x;
    }
    sort(orden, orden+cad.length(),comp);
  /*  for(int x=0; x<cad.length(); x++)
        cout<<orden[x].car<<" ";
    cout<<endl;
    for(int x=0; x<cad.length(); x++)
        cout<<orden[x].pos<<" ";
        cout<<endl;*/
    while(n--)
    {
        cin>>car>>abajo>>arriba;
        arriba+=abajo;
        cout<<solve(cad.length(), abajo, arriba, car)<<"\n";
    }
}
