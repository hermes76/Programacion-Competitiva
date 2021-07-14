#include <iostream>
using namespace std;

int main()
{
    locale::global(locale("spanish"));
    string pal;
    cin>>pal;
    if(pal[0]=='E')
    {
        cout<<"Bienvenido agente especial.\nSu misión es:Romper con\nlos paradigmas de la\nprogramación.Este mensaje\nde autodestruirá en\n10 segundos.";
    }else{
        cout<<"Clave incorrecta! Morirás\n en10 segundos";
    }
}
