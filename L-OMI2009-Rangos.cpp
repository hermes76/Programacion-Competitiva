#include <iostream>
#include <algorithm>
using namespace std;
struct doble
{
    int a,b;
};
bool comp(doble a , doble b)
{
    if(a.a<b.a)return 1;
    return 0;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m,s;
    long long int aux,aux2,original;
    cin>>n>>m>>s;
    doble arr[m];
    int num,num2;
    long long int cuenta;
    for(int x=0; x<m; x++)cin>>arr[x].a>>arr[x].b;
    sort(arr,arr+m,comp);
    for(int y=0; y<s; y++)
    {
        cin>>num>>num2;
        cuenta=0;
        for(int x=0; x<m; x++)
        {
            if(arr[x].a<=num2 and arr[x].b >=num)
            {
                aux=(arr[x].b-arr[x].a)+1;
                aux=(aux*(aux+1)/2);
                original=aux;
                if(arr[x].a<num)
                {
                    aux2=(num-arr[x].a);
                    aux2=aux2*(aux2+1)/2;
                    aux-=aux2;
                }
                if (arr[x].b>=num2)
                {
                    aux2=(num2-arr[x].a)+1;
                    aux2=aux2*(aux2+1)/2;
                    aux-=original-aux2;
                }
                cuenta+=aux%10000;
                cuenta%=10000;
            }
        }
        cout<<cuenta<<'\n';
    }


}
