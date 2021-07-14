#include <iostream>
using namespace std;

int main()
{
    int n,len;
    cin>>n;
    string arr;
    while(n--)
    {
        cin>>len;
        cin>>arr;
        int cuenta=0;
        int indice=1;
        int ant=0;
        int indice2=0;
        for(int x=0; x<len; x++)
        {
            if(indice==arr[x]-'0' +ant)
            {
                if(indice2!=0)
                {
                    cuenta+=x+1-indice2;
                    indice2=0;
                }
                indice2=x+1;
                cuenta++;
            }else if(arr[x+1]!=0)
            {
                indice=1;
                ant=0;
            }
            indice++;
            ant+=arr[x]-'0';
        }
        cout<<cuenta<<endl;
    }
}
