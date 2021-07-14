#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[5]={580,980,1190,1250,1420};
    int res=100000;
    string texto;
    if(n>1520 or n<540)cout<<"error";
    else{
        for(int x=0; x<5; x++)
        {
           res=min(res,abs(n-arr[x]));
           if(res==abs(n-arr[x]))
              {
                if(n<arr[x])
                {
                    texto="adelante";
                }else{
                    texto="atras";
                }
              }
        }
        cout<<texto<<" "<<res;
    }
}
