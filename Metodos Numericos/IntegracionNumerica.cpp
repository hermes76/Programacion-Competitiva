#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.1416
#define e 2.7182
//Formula
#define F(x) (2*x)/(pow(x,2)+4)
using namespace std;

int main()
{
    //cout<<setprecision(5);
    cout<<"Numero de intervalos : ";
    int n;
    cin>>n;
    double a,b;
    cout<<"Limite inferior : ";
    cin>>a;
    cout<<"Limite superior : ";
    cin>>b;
    int opcion;
    cout<<"Metodos"<<endl;
    cout<<"Trapecio :1 , Simpson 1/3 = 2, Simpson 3/8 = 3"<<endl;
    cin>>opcion;
    double dx=(b-a)/n;
    double valor=a;
    double res=0;
    double ai=a,bi=a+dx;
    if(opcion==1)
    {
        for(int x =0; x<n; x++)
        {
            cout<<"Intervalo "<<x<<endl;
            res+=(bi-ai)*(F(ai)+F(bi))/2;
            cout<<"F("<<ai<<") = "<<F(ai)<<endl;
            cout<<"F("<<bi<<") = "<<F(bi)<<endl;
            cout<<"I = "<<(bi-ai)*(F(ai)+F(bi))/2<<endl<<endl;
            ai=bi;
            bi=bi+dx;
        }
        cout<<"Resultado es = "<<res;
    }else if(opcion ==2)
    {
        dx=(b-a)/2;
        res=dx*(F(a)+4*F((a+b)/2)+F(b))/3;
        cout<<"Resultado = "<<res;
      /*  res+=F(a)+F(b);
        double sumatoria=0;
        cout<<"desarrollo de primera sumatoria"<<endl;
        for(int x =1; x<n/2; x++)
        {
            sumatoria+=F(a+(2*x)*dx);
            cout<<"F("<<a+(2*x)*dx<<") = "<<F(a+(2*x)*dx)<<endl;
        }
        sumatoria*=2;
        cout<<endl<<"Sumatoria multiplicada por 2 = "<<sumatoria<<endl<<endl;
        res+=sumatoria;
        sumatoria=0;
         cout<<"desarrollo de segunda sumatoria"<<endl;
        for(int x =1; x<=n/2; x++)
        {
            sumatoria+=F(a+((2*x)-1)*dx);
             cout<<"F("<<a+((2*x)-1)*dx<<") = "<<F(a+((2*x)-1)*dx)<<endl;
        }
        sumatoria*=4;
        cout<<endl<<"Sumatoria multiplicada por 2 = "<<sumatoria<<endl<<endl;
        res+=sumatoria;
        res=dx*res/3;
        cout<<"Resultado es = "<<res;*/
    }else if(opcion==3){
        dx=(b-a)/3;
        res=(0.9)*(F(a)+(3*F((a+dx)))+(3*F((a+(2*dx))))+F(b))/8;
        cout<<"Resultado = "<<res;
         /*res+=F(a)+F(b);
        double sumatoria=0;
        cout<<"desarrollo de primera sumatoria"<<endl;
        for(int x =1; x<n-1; x+=3)
        {
            sumatoria+=F(a+x*dx);
            cout<<"F("<<a+x*dx<<") = "<<F(a+x*dx)<<endl;
        }
        sumatoria*=3;
         cout<<endl<<"Sumatoria multiplicada por 3 = "<<sumatoria<<endl<<endl;
        res+=sumatoria;
        sumatoria=0;
        cout<<"desarrollo de segunda sumatoria"<<endl;
        for(int x =2; x<n; x+=3)
        {
            sumatoria+=F(a+x*dx);
            cout<<"F("<<a+x*dx<<") = "<<F(a+x*dx)<<endl;
        }
        sumatoria*=3;
         cout<<endl<<"Sumatoria multiplicada por 3 = "<<sumatoria<<endl<<endl;
        res+=sumatoria;
        sumatoria=0;
        cout<<"desarrollo de tercera sumatoria"<<endl;
        for(int x =3; x<n-2; x+=3)
        {
             sumatoria+=F(a+x*dx); 
            cout<<"F("<<a+x*dx<<") = "<<F(a+x*dx)<<endl;
        }
        sumatoria*=2;
         cout<<endl<<"Sumatoria multiplicada por 2 = "<<sumatoria<<endl<<endl;
        res+=sumatoria;
        res=3*dx*res/8;
        cout<<"Resultado es = "<<res;*/
    }

}