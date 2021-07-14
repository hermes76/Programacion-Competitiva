//*******************************************************************//
//***********************METODO**lAGRANGE****************************//
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
//**EJEMPLOS DEL MANUAL**********************************************//
//**Ejemplo 5.3. - Obtener el polinomio interpolante de Lagrange*****// 
//**de 2o. grado para los siguientes datos:**************************//
//***_________*******************************************************//
//**|X  |F(X)|*******************************************************//
//**|1.3|0.87|*******************************************************//
//**|1.6|0.73|*******************************************************//
//**|1.9|0.56|*******************************************************//
//**----------*******************************************************//
//*******************************************************************//
//**COMO SOLO NOS IMPORTA EL POLINOMIO SE DEBERA DE TECLEAR DE LA****//
//**LA SIGUIENTE MANERA**********************************************//
//3                    **********************************************//
//1.3                  **********************************************//
//0.87                 **********************************************//
//1.6                  **********************************************//
//0.73                 **********************************************//
//1.9                  **********************************************//
//0.56                 **********************************************//
//2                    **********************************************//
//0                    **********************************************//
//*******************************************************************//
//**Ejemplo 5.4.- Utilizando el polinomio de Lagrange apropiado de***// 
//**grado 1,2,3 obtener f (9).***************************************//
//*******************************************************************//
//**_______________________________**********************************//
//**|x   | 3 |  7 |  15 | 22 | 30 |**********************************//
//**|f(x)| 1 | -8 | -22 | -9 | 12 |**********************************//
//**-------------------------------**********************************//
//*******************************************************************//
//**GRADO 1**********************************************************//
//**SE DEBERA TECLEAR DE LA SIGUIENTE MANERA*************************//
//*******************************************************************//
//5                     *********************************************//
//3                     *********************************************//
//1                     *********************************************//
//7                     *********************************************//
//-8                    *********************************************//
//15                    *********************************************//
//-22                   *********************************************//
//22                    *********************************************//
//-9                    *********************************************//
//30                    *********************************************//
//12                    *********************************************//
//1                     *********************************************//
//1                     *********************************************//
//9                     *********************************************//
//**GRADO 2**********************************************************//
//**SE DEBERA TECLEAR DE LA SIGUIENTE MANERA*************************//
//*******************************************************************//
//5                     *********************************************//
//3                     *********************************************//
//1                     *********************************************//
//7                     *********************************************//
//-8                    *********************************************//
//15                    *********************************************//
//-22                   *********************************************//
//22                    *********************************************//
//-9                    *********************************************//
//30                    *********************************************//
//12                    *********************************************//
//2                     *********************************************//
//0                     *********************************************//
//9                     *********************************************//
//**GRADO 3**********************************************************//
//**SE DEBERA TECLEAR DE LA SIGUIENTE MANERA*************************//
//*******************************************************************//
//5                     *********************************************//
//3                     *********************************************//
//1                     *********************************************//
//7                     *********************************************//
//-8                    *********************************************//
//15                    *********************************************//
//-22                   *********************************************//
//22                    *********************************************//
//-9                    *********************************************//
//30                    *********************************************//
//12                    *********************************************//
//3                     *********************************************//
//0                     *********************************************//
//9                     *********************************************//
//*******************************************************************//
#include <iostream>
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
int Lni(int N,int I,int R1,Puntos puntos[],Variable LocalEcuacion[])
{
    bool activador=1;
    int tam=2;
    Variable LocalAuxEcuacion[1000];
    Variable Local;
    for(int x =R1; x<=N+R1; x++)
    {
        if(x!=I)
        {
            double division= puntos[I].X-puntos[x].X;
            if(activador)
            {
                LocalEcuacion[1].Coeficiente=1/division;
                LocalEcuacion[1].Grado=1;
                LocalEcuacion[0].Coeficiente=(-1*puntos[x].X)/division;
                LocalEcuacion[0].Grado=0;
               /* cout<<"Xi "<<puntos[I].X<<" Xj "<<puntos[x].X;
                cout<<"Locals bools";
                cout<<LocalEcuacion[1].Coeficiente;
                cout<<"X^"<<LocalEcuacion[1].Grado<<" + ";
                cout<<LocalEcuacion[0].Coeficiente;
                cout<<"X^"<<LocalEcuacion[0].Grado<<endl;*/
                activador=0;
            }else{
                
                for(int y=0; y<tam; y++)
                {
                    LocalAuxEcuacion[y].Coeficiente=LocalEcuacion[y].Coeficiente;
                    LocalAuxEcuacion[y].Grado=LocalEcuacion[y].Grado;
                }
                Local.Coeficiente=1/division;
                Local.Grado=1;
               /* cout<<"Locals ";
                cout<<Local.Coeficiente;
                cout<<"X^"<<Local.Grado<<" + ";*/
                for(int y=0; y<tam; y++)
                {
                    LocalEcuacion[y+1].Coeficiente=LocalAuxEcuacion[y].Coeficiente*Local.Coeficiente;
                    LocalEcuacion[y+1].Grado=LocalAuxEcuacion[y].Grado+Local.Grado;
                }
                Local.Coeficiente=(-1*puntos[x].X)/division;
                Local.Grado=0;
               /* cout<<Local.Coeficiente;
                cout<<"X^"<<Local.Grado<<" + ";
                cout<<" final";*/
                LocalEcuacion[0].Coeficiente=LocalAuxEcuacion[0].Coeficiente*Local.Coeficiente;
                /*cout<<LocalEcuacion[0].Coeficiente;
                cout<<"X^"<<LocalEcuacion[0].Grado<<" + ";*/
                for(int y=1; y<tam; y++)
                {
                    LocalEcuacion[y].Coeficiente +=LocalAuxEcuacion[y].Coeficiente * Local.Coeficiente;
                    /*cout<<LocalEcuacion[y].Coeficiente;
                    cout<<"X^"<<LocalEcuacion[y].Grado<<" + ";*/
                }
                tam++;
            }
        }
    }
    return tam;
}
int Lagrange(int N,int NumPuntos,Puntos puntos[])
{   int R1=0;
    int tam=0;
    int MaxTam=0;
    if(N+1<NumPuntos)
    {
        cout<<"Ingrese el incio del rango a interpolar: ";
        cin>>R1;
    }
    if(R1+N<NumPuntos)
    {
        for(int x=R1; x<=N+R1; x++)
        {
            Variable LocalEcuacion[1000];
            tam=Lni(N,x,R1,puntos,LocalEcuacion);
            MaxTam=max(tam,MaxTam);
            for(int y=0; y<tam; y++)
            {
                Ecuacion[y].Coeficiente +=LocalEcuacion[y].Coeficiente*puntos[x].Y;
                Ecuacion[y].Grado =LocalEcuacion[y].Grado;
            }
        }
        return MaxTam;
    }else{
        cout<<"No se pudo hacer la intepolacion";
        return -1;
    }

}
int main()
{
    cout<<setprecision(Precision);
    cout<<fixed;
    int NumPuntos;
    int n;
    int tam;
    double num;
    double res;
    cout<<"Numero de puntos de a grafica: ";
    cin>>NumPuntos;
    Puntos puntos[NumPuntos];
    for(int x =0; x<NumPuntos; x++)
    {
        cout<<"X"<<x<<": ";
        cin>>puntos[x].X;
        cout<<"F(X"<<x<<"): ";
        cin>>puntos[x].Y;
    }
    cout<<"Interpolacion de grado: ";
    cin>>n;
    tam=Lagrange(n,NumPuntos,puntos);
    cout<<"Numero a sustituir en la funcion generada: ";
    cin>>num;
    cout<<endl<<"F(X)= ";
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