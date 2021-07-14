#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    int impar=0,par=0;
    for(int x =0; x<n; x++)
    {
        cin>>m;
        if(m%2==0)
        {
            par++;
        }else{
            impar++;
        }
    }
    cout<<par<<" "<<impar;
}