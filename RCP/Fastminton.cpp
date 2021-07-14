#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int izq=0,der=0;
    int juegoiz=0,juegoder=0;
    bool dir=0;
    string cad;
    cin>>cad;
    for(int x=0; x<cad.length(); x++)
    {
        if(cad[x]=='S')
        {
            if(dir==0)
            {
                izq++;
            }else
            der++;
        }
        else if(cad[x]=='R')
        {
            dir=!dir;
             if(dir==0)
            {
                izq++;
            }else
            der++;
        }
         if(izq>=5 and izq-der>=2)
        {
            juegoiz++;
            izq=0;
            der=0;
        }
        if(der>=5 and der-izq>=2)
        {
            juegoder++;
            izq=0;
            der=0;
        }
        if(der==10)
        {
            juegoder++;
            izq=0;
            der=0;
        }
        if(izq==10)
        {
            juegoiz++;
            izq=0;
            der=0;
        }
        if(cad[x]=='Q')
        {
            if(juegoiz>=2)
            {
                cout<<juegoiz<<" (winner)"<<" - "<<juegoder;
            }
            else if(juegoder>=2)
            {
                cout<<juegoiz<<" - "<<juegoder<<" (winner)";
            }else if(dir==0)
            {
                cout<<juegoiz<<" ("<<izq<<"*) - "<<juegoder<<" ("<<der<<")";
            }else
            {
                 cout<<juegoiz<<" ("<<izq<<") - "<<juegoder<<" ("<<der<<"*)";
            }
            cout<<endl;
        }
    }
}
