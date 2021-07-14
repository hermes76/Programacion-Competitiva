#include <iostream>
using namespace std;
int main()
{
    int n;
    int a,b;
    cin>>n;
    for(int x=0; x<n; x++)
    {
        cin>>a>>b;
        if((a+b)%3 ==0 && (a!=0 || b!=0))
        {
            int mayor;
            int menor;
            if(a>b)
            {
                mayor=a;
                menor=b;
            }else{

            mayor=b;
            menor=a;
            }
            if(mayor/2<=menor)
            {
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else if(a==0 && b==0)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
