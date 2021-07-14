//*******************************************************************//
//***********************METODO**NEWTON******************************//
//*****************JESUS**HERMES**SOLIS**SALDAÑA*********************//
//¿COMO USAR?********************************************************//
//**1.-INGRESAR EL NUMERO DE PUNTOS DE LA GRAFICA********************//
//**2.-INGRESAR LOS N PUNTOS DE LA GRAFICA***************************//
//**3.-INGRESAR EL GRADO DEL POLINOMIO DE LAGRANGE*******************//
//**4.-SI EL POLINOMIO DE INTEPOLACION NO INTERPOLA TODOS LOS DATOS**//
//**SE DEBE DE PONER LA POSICION EN DONDE SE ENCUENTRA EL DATO A*****//
//**INTERPOLAR*******************************************************//
//**5.-COLOCAR UN VALOR PARA SUSTITUIR EN LA FUNCION GENERADA********//
//*******************************************************************//
//**PARA EL EXAMEN TECLEAR LOS SIGUIENTES DATOS**********************//
//**PARA EL POLINOMIO DE 3 GRADO ************************************//
/*
//5
//1.0
//-1.6
//2.0
//-0.4
//2.5
//0.1
//3.0
//0.7
//4.0
//1.8
//3
//0
//3
*/
//**PARA MOSTRAR LA TABLA DE DIFERENCIAS DIVIDIDAS COMPLETA***********//
/*
//5
//1.0
//-1.6
//2.0
//-0.4
//2.5
//0.1
//3.0
//0.7
//4.0
//1.8
//4
//0
//3
*/
#include  <iostream>
#include <iomanip>
#include <math.h>
#define Precision 12
using namespace std;

struct Puntos
{
    double X;
    double Y;
};
struct Variable
{
    double Coeficiente;
    int Grado;
};
Variable Ecuacion[1000];
double Valores[1000][1000];
int menor;
double F(int X1,int  X2, Puntos puntos[])
{
    double A,B,Res;
    if(X1==X2)
    {
        Valores[X1-menor][0]=puntos[X1].Y;
        return puntos[X1].Y;
    }
    if(Valores[X2-menor][X2-X1]==0)
    {
        A=F(X1,X2-1,puntos);
        B=F(X1+1,X2,puntos);
        Res=(B-A)/(puntos[X2].X-puntos[X1].X);
       // cout<<"X1 "<<X1<<" X2 "<<X2<<" Res "<<Res<<endl;
        Valores[X2-menor][X2-X1]=Res;
        return Res;
    }else{
        return Valores[X2-menor][X2-X1];
    }
}
int Productorio(int X1,int X2,Variable LocalEcuacion[],Puntos puntos[])
{
    int tam=1;
    Variable LocalAuxEcuacion[1000];
    for(int x=X1; x<X2; x++)
    {
        if(x==X1)
        {
            LocalEcuacion[1].Coeficiente=1;
            LocalEcuacion[1].Grado=1;
            LocalEcuacion[0].Coeficiente=-1*puntos[x].X;
            LocalEcuacion[0].Grado=0;
        }else{
            for(int y =0; y<tam; y++)
            {
                LocalAuxEcuacion[y].Coeficiente=LocalEcuacion[y].Coeficiente;
                LocalAuxEcuacion[y].Grado=LocalEcuacion[y].Grado;
            }
            for(int y =0; y<tam; y++)
            {
                LocalEcuacion[y+1].Coeficiente=LocalAuxEcuacion[y].Coeficiente;
                LocalEcuacion[y+1].Grado=LocalAuxEcuacion[y].Grado+1;
            }
            LocalEcuacion[0].Coeficiente=LocalAuxEcuacion[0].Coeficiente*-1*puntos[x].X;
            for(int y =1; y<tam; y++)
            {
                LocalEcuacion[y].Coeficiente+=LocalAuxEcuacion[y].Coeficiente*-1*puntos[x].X;
            }
        }
        tam++;
    }
    return tam;
}
int Newton(int X1, int X2,int Grado, Puntos puntos[])
{
    int tam=0;
    int MaxTam=0;
    Ecuacion[0].Coeficiente = puntos[X1].Y;
    F(X1,X2,puntos);
    cout<<endl<<"TABLA DE DIFERENCIAS DIVIDIDAS"<<endl;
    for(int x =0; x<=Grado; x++)
    {
        for(int y =0; y<=Grado; y++)
        {
            cout<<Valores[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int x =X1+1; x<=Grado+X1; x++)
    {
        Variable LocalEcuacion[1000];
        tam=Productorio(X1,x,LocalEcuacion,puntos);
        MaxTam=max(tam,MaxTam);
        for(int y =0; y<tam; y++)
        {
            //cout<<"Productorio "<<LocalEcuacion[y].Coeficiente<<"x^"<<LocalEcuacion[y].Grado<<endl;
            //cout<<"Mult "<<LocalEcuacion[y].Coeficiente*Valores[x][x]<<"X^"<<LocalEcuacion[y].Grado<<endl;
            //cout<<Valores[x-menor][x-menor]<<endl;*/
            Ecuacion[y].Coeficiente+=LocalEcuacion[y].Coeficiente*Valores[x-menor][x-menor];
            Ecuacion[y].Grado=LocalEcuacion[y].Grado;
        }
    }
    return MaxTam;
}
int main()
{
    cout<<setprecision(Precision);
    cout<<fixed;
    cout<<"Numero de puntos de a grafica: ";
    int NumPuntos;
    cin>>NumPuntos;
    int tam=0;
    Puntos puntos[NumPuntos];
    for(int x =0; x<NumPuntos; x++)
    {
        cout<<"X"<<x<<": ";
        cin>>puntos[x].X;
        cout<<"F(X"<<x<<"): ";
        cin>>puntos[x].Y;
    }
    int Grado;
     cout<<"Interpolacion de grado: ";
    cin>>Grado;
    int X1;
    cout<<"Rango de inicio de intepolacion: ";
    cin>>X1;
    menor=X1;
    tam=Newton(X1,X1+Grado,Grado,puntos);
    double num;
    cout<<"Numero a sustituir en la funcion generada: ";
    cin>>num;
    cout<<endl<<"F(X)= ";
    double res=0;
    for(int x=tam-1; x>=0; x--)
    {
        if(Ecuacion[x].Coeficiente>=0)
        {
            cout<<" + ";
            cout<<Ecuacion[x].Coeficiente;
        }else{
            cout<<" - ";
            cout<<-1*Ecuacion[x].Coeficiente;
        }
        if(Ecuacion[x].Grado >0)
        {
            cout<<"X^";
            cout<<Ecuacion[x].Grado;
        }
        res+=Ecuacion[x].Coeficiente * pow(num,Ecuacion[x].Grado);
    }
    cout<<endl<<"F("<<num<<")= "<<res;
}