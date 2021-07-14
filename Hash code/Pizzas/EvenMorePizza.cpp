#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include <unordered_map>
using namespace std;

ofstream fout ("out3.txt");
ifstream fin ("a.txt");


struct delicioso
{
    int num;
    vector <string> ingredientes;
};

long long int pizzas, dobles, triples, cuadruples,auxpizza;
    vector<delicioso> disponibles;
    vector<delicioso> menu;
    string ingrediente;
int solucion =0;
 long long int puntuacion=70;

int distinto(int n, int m)
{
    int solucion;
    do
    {
        solucion =rand()%m;
        cout<<"D1 "<<n<<" "<<solucion<<endl;
    }
    while(n==solucion);
    return solucion;
}
int distinto2(int n, int a, int m)
{
    int solucion;
    do
    {
        solucion =rand()%m;
        cout<<"D2 "<<n<<" "<<a<<" "<<m<<" "<<solucion<<endl;
    }
    while(n==solucion or a==solucion);
    return solucion;
}
int distinto3(int n,int a,int b,  int m)
{
    int solucion;
    do
    {
        solucion =rand()%m;
         cout<<"D3 "<<n<<" "<<a<<" "<<b<<" "<<solucion<<endl;
    }
    while(n==solucion or a==solucion or b==solucion);
    return solucion;
}
long long int solve()
{
    auxpizza=pizzas;
    int num[4];
    long long int puntuacion=0;
    long long int dos=0;
    long long int tres=0;
    long long int cuatro=0;
    long long int auxnum;
    string aux;
    for(int x =0; x<dobles and pizzas>=2; x++)
    {
        unordered_map <string, int> mapa;
        num[0]=rand()%pizzas;
        num[1]=distinto(num[0],pizzas-1);
        disponibles.erase(disponibles.begin()+num[1]);
        auxnum=0;
        fout<<2<<" "<<num[0]<<" "<<num[1]<<"\n";
        pizzas-=2;
        for(int y=0; y<2; y++)
        {
            for(int z=0; z<disponibles[num[y]].num; z++)
            {
                aux=disponibles[num[y]].ingredientes[z];
               if(mapa[aux]==0)
               {
                    auxnum++;
               }
                else mapa[aux]++;
            }
        }
        dos+=auxnum*auxnum;
        for(int x=0; x<2; x++)disponibles.erase(disponibles.begin()+num[x]);
    }
      for(int x =0; x<triples and pizzas>=3; x++)
    {
        unordered_map <string, int> mapa;
        num[0]=rand()%pizzas;
        num[1]=distinto(num[0],pizzas-1);
        num[2]=distinto2(num[0],num[1],pizzas-2);
        disponibles.erase(disponibles.begin()+num[2]);
        auxnum=0;
        fout<<3<<" "<<num[0]<<" "<<num[1]<<" "<<num[2]<<"\n";
        pizzas-=3;
         for(int y=0; y<3; y++)
        {
            for(int z=0; z<disponibles[num[y]].num; z++)
            {
                aux=disponibles[num[y]].ingredientes[z];
               if(mapa[aux]==0)
                auxnum++;
                else mapa[aux]++;
            }
        }
        tres+=auxnum*auxnum;
        for(int x=0; x<2; x++)disponibles.erase(disponibles.begin()+num[x]);
    }
      for(int x =0; x<cuadruples and pizzas>=4; x++)
    {
        unordered_map <string, int> mapa;
        num[0]=rand()%pizzas;
        num[1]=distinto(num[0],pizzas-1);
        num[2]=distinto2(num[0],num[1],pizzas-2);
        num[3]=distinto3(num[0],num[1],num[2],pizzas-3);
        auxnum=0;
       fout<<3<<" "<<num[0]<<" "<<num[1]<<" "<<num[2]<<" "<<num[3]<<"\n";
        pizzas-=4;
        for(int y=0; y<4; y++)
        {
            for(int z=0; z<disponibles[num[y]].num; z++)
            {
                aux=disponibles[num[y]].ingredientes[z];
               if(mapa[aux]==0)
                auxnum++;
                else mapa[aux]++;
            }
        }
        cuatro+=auxnum*auxnum;
        for(int x=0; x<2; x++)disponibles.erase(disponibles.begin()+num[x]);
    }
    puntuacion=dos+tres+cuatro;
    return puntuacion;
}
void llenar()
{
    pizzas=auxpizza;
    disponibles.clear();
    for(int x=0; x<pizzas; x++)
    {
        disponibles.push_back(menu[x]);
    }
}
int main()
{
    srand(time(NULL));
    long long int res;
    long long int veces=0;
    fin>>pizzas>>dobles>>triples>>cuadruples;
    for(int x=0; x<pizzas; x++)
    {
        delicioso horno;
        fin>>horno.num;
        for(int y =0; y<horno.num; y++)
        {
            fin>>ingrediente;
            horno.ingredientes.push_back(ingrediente);
        }
        disponibles.push_back(horno);
        menu.push_back(horno);
    }/*
    for(int x=0; x<100; x++)
    {
        cout<<rand();
    }*/

    do
    {
        res=solve();
        //cout<<res<<endl;
        llenar();
        veces++;
        cout<<veces<<" "<<res<<endl;
    }while(res<=solucion);
}
