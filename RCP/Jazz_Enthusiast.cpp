#include <iostream>
using namespace std;
int main()
{
    int canciones, tiempo;
    int horas=0,minutos=0,segundos=0,auxminutos,auxsegundos;
    cin>>canciones>>tiempo;
    char puntos;
    for(int x=0; x<canciones; x++)
    {
        cin>>auxminutos>>puntos>>auxsegundos;
        if(x>=1)
        {
            segundos-=tiempo;
        }
        minutos+=auxminutos;
        segundos+=auxsegundos;
    }
    minutos+=segundos/60;
    segundos%=60;
    horas+=minutos/60;
    minutos%=60;
    if(segundos <0)
    {
        segundos=60+segundos;
        minutos--;

    }
    if(minutos<0)
    {
        minutos=60+minutos;
        horas--;
    }
    if(horas<10)
    {
        cout<<'0';
    }
    cout<<horas<<':';
    if(minutos<10)
    {
        cout<<'0';
    }
    cout<<minutos<<':';
    if(segundos<10)
    {
        cout<<'0';
    }
    cout<<segundos;
    cout<<endl;


}
