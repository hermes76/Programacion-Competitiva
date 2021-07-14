#include <iostream>
using namespace std;

int main()
{
    int n;
    int indice=8;
    int mejor=0;
    cin>>n;
    int arr[9];
    arr[0]=1;
    for(int x=1; x<9; x++)arr[x]=arr[x-1]*x;
    while(n>0)
    {
        if(arr[indice]<=n)
        {
            n-=arr[indice];
            mejor++;
        }
        else indice--;
    }
    cout<<mejor<<endl;
}
