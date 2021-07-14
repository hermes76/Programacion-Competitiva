#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string cad;
    queue <string>cola;
    stack <string>pila;
    getline(cin,cad);
    int len=cad.length();
    string aux="";
    for(int x=0; x<len; x++)
    {
        if(cad[x]==']')
        {
            for(int y=x+1; y<len and cad[y]!='[' and cad[y]!=']'; y++)aux+=cad[y];
            cola.push(aux);
            aux="";
        }else if(cad[x]=='[')
        {
            for(int y=x+1; y<len and cad[y]!='[' and cad[y]!=']'; y++)aux+=cad[y];
            pila.push(aux);
            aux="";
        }
    }
    while(!pila.empty())
    {
        cout<<pila.top();
        pila.pop();
    }
    for(int y=0; y<len and cad[y]!='[' and cad[y]!=']'; y++) cout<<cad[y];
    while(!cola.empty())
    {
        cout<<cola.front();
        cola.pop();
    }
}
