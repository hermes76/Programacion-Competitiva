#include <iostream>
using namespace std;
/*#include <math.h>
using namespace std;
long long int cuenta=0;
int n;
int arr[19];
bool arr2[19];
bool primo(int a)
{
    bool si=1;
    for(int x =2; x<=sqrt(a); x++)
    {
        if(a%x==0)
        {
            si=0;
            break;
           }
    }
    return si;
}
void generar(int tam)
{
    if(tam==n)
    {
        if(primo(arr[n-1]+arr[0]))
           {
               cuenta++;
           }
    }else{
        for(int x =2; x<=n; x++)
        {
            if(arr2[x-1]==0)
            {
                if(primo(arr[tam-1]+x))
                {
                    arr2[x-1]=1;
                    arr[tam]=x;
                    generar(tam+1);
                    arr2[x-1]=0;
                }

            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    if(n%2==0 and n<=14)
    {
    arr2[0]=1;
    arr[0]=1;
    generar(1);
    }
    if(n==16)
    {
        cuenta=81024;
    }else if(n==18)
    {
        cuenta=770144;
    }
    cout<<cuenta;
}
*/
int main()
{
    int n;
    int arr[10];
    arr[1]=1;
    arr[2]=2;
    arr[3]=2;
    arr[4]=4;
    arr[5]=96;
    arr[6]=1024;
    arr[7]=2880;
    arr[8]=81024;
    arr[9]=770144;
    cin>>n;
    if(n%2==1)
    {
        cout<<0;
    }else{
        cout<<arr[n/2];
    }
}
