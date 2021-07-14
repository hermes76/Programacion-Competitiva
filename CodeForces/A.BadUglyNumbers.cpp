#include <iostream>
#include <math.h>
using namespace std;

int number(int a)
{
    int digito;
    int aux;
    int raiz;
    a=pow(10,a-1);
    for(int x =a; x<a*10; x++)
    {
        aux=x;
        do
        {
            digito=aux%10;
            aux/=10;
        }
        while(aux!=0 && digito !=0 && x%digito!=0 && digito!=1);
        if(aux==0 && digito !=1 && digito != 0)
        {
            return x;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    int s;
    for(int x =0; x<n; x++)
    {
        s=number(arr[x]);
        if(s!=0)
        {
            cout<<s<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
}
