#include <iostream>
#include <algorithm>
using namespace std;
struct invitado
{
    int a,b,c;
};
bool comp(invitado a,invitado b)
{
    if(a.a< b.a)
        return 1;
    return 0;
}
int main()
{
    int globos,n;
    cin>>globos>>n;
    invitado arr[n];
    for(int x=0; x<n; x++)cin>>arr[x].a>>arr[x].b>>arr[x].c;
    sort(arr,arr+n,comp);

}
