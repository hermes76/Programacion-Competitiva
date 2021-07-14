#include <iostream>
#include <queue>
using namespace std;
struct nombres{
    string nom;
    bool act;
};
int main()
{
    string can;
    int palabras=1;
    getline(cin,can);
    int eliminado=0;
    for(int x =0; x<can.length(); x++)
    {
        if(can[x]==' ')
        {
            palabras++;
        }
    }
    int n;
    cin>>n;
    string nom[n];
    queue <string> pila1;
    queue <string> pila2;
    nombres arr[n];
    string pal;
    cout<<palabras<<endl;
    for(int x =0; x<n; x++)
    {
        cin>>pal;
        arr[x].nom=pal;
        arr[x].act=0;
    }
    int indice=0;
    indice = (palabras-1)%n;
    bool equipo=0;
    while(eliminado<=n)
    {
        while(arr[indice].act==1)
        {
            indice++;
            indice%n;
        }
        arr[indice].act=1;
        if(equipo==0)
        {
            pila1.push(arr[indice].nom);
            equipo=1;
        }else{
            pila2.push(arr[indice].nom);
            equipo=0;
        }
        eliminado++;
        while(arr[indice].act==1)
        {
            indice++;
            indice%n;
        }
        indice=(indice+palabras-1)%n;
    }
    cout<<pila1.size()<<'\n';
    while(!pila1.empty())
    {
        cout<<pila1.front()<<'\n';
        pila1.pop();
    }
    cout<<pila2.size()<<'\n';
    while(!pila2.empty())
    {
        cout<<pila2.front()<<'\n';
        pila2.pop();
    }
}