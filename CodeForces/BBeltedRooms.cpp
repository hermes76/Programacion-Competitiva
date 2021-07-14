#include <iostream>
using namespace std;

int main()
{
    int n,m,cuenta,cuenta2,res;
    char aux;
    bool p;
    cin>>n;
    string cad;
    while(n--)
    {
        cin>>m;
        cin>>cad;
        cuenta=1;
        cuenta2=0;
        aux='.';
        res=0;
        p=0;
        for(int x=0; x<m; x++)
        {
            if(cad[x]=='-')
            {
                cuenta++;
                res=cuenta;
            }
            else{
                if(aux=='.')aux=cad[x];
                if(aux==cad[x])cuenta2++;
                else{cuenta2=0;p=1;cuenta=1;}
            }
        }
        if(!p)res+=cuenta2;
        cout<<res<<'\n';
    }
}
