#include <iostream>
using namespace std;

int arr[26];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int lon=n;
    char cad;
    int impares=0;
    for(int x=0; x<n; x++)
    {
        cin>>cad;
        arr[cad-97]++;
    }
    for(int x =0; x<27; x++)
    {
       if(arr[x]%2==1)impares++;
    }
    for(n; n>=0; n--)
    {
        if(n%2==0)
        {
            if(impares==0)break;
            if(impares>=1)
            {
                impares--;
            }
        }else{
            if(impares==1)break;
            if(impares>1)
            {
                impares--;
            }
        }
    }
    cout<<lon-n;
}
