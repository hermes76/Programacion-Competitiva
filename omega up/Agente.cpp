#include <iostream>

using namespace std;

int main()
{
    string pal;
    cin>>pal;
    char o=162;
    char a = 160;
    if(pal=="Einstein")
    {
        cout<<"Bienvenido agente especial.\nSu misi"<<o<<"n es:Romper con\nlos paradigmas de la\nprogramaci"<<o<<"n.Este mensaje\nde autodestruir"<<a<<" en\n10 segundos.";
    }else if(pal=="Newton"){
        cout<<"Clave incorrecta! Morir"<<a<<"s\nen 10 segundos";
    }
}
