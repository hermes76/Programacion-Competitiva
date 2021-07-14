#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        string cad[a];
        int abc[26];
        int maximo;
        bool h[a];
        char aux;
        bool p=0;
        string res;
        for(int x=0; x<a; x++)h[x]=0;
        for(int x=0; x<a; x++)cin>>cad[x];
        for(int x=0; x<b and !p; x++)
        {
            for(int y=0; y<26; y++)abc[y]=0;
            maximo=0;
            for(int y=0; y<a; y++)
            {
                abc[cad[x][y]-'a']++;
                if(maximo<abc[cad[x][y]-'a'])
                {
                    aux=cad[x][y];
                    maximo=abc[cad[x][y]-'a'];
                }
            }
            res+=aux;
            for(int y=0; y<a and !p; y++)
            {
                if(cad[x][y]!=aux)
                {
                    if(h[y]==0)
                        h[y]=1;
                    else
                        p=1;
                }
            }
        }
        if(!p)
            cout<<res;
        else cout<<-1;
        cout<<'\n';
    }
}
