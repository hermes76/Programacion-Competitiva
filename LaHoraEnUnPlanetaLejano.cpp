#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dias,horas,minutos,segundos;
    minutos = n/50;
    horas = minutos/70;
    minutos = minutos%70;
    dias=horas/12;
    horas=horas%12;
    segundos=n-minutos*50-horas*70*50-dias*12*70*50;
    cout<<dias<<" "<<horas<<" "<<minutos<<" "<<segundos;
}