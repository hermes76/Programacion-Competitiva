#include <iostream>
using namespace std;

int main()
{
    locale::global(locale("spanish"));
    string pal;
    cin>>pal;
    if(pal[0]=='E')
    {
        cout<<"Bienvenido agente especial.\nSu misi�n es:Romper con\nlos paradigmas de la\nprogramaci�n.Este mensaje\nde autodestruir� en\n10 segundos.";
    }else{
        cout<<"Clave incorrecta! Morir�s\n en10 segundos";
    }
}
