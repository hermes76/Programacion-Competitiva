#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;
struct pos{
    int num;
    int x;
    int y;
};
int n,m;
vector<pos> vect;
int arr[2502];
bool comp(pos a , pos b)
{
    if(a.num<b.num)
        return 1;
    return 0;
}
pos Suma(pos a, int num)
{
    pos mejor;
    mejor.num=INF;
    int suma;
    for(int x=arr[num]; vect[arr[num]].num==vect[x].num; x++)
    {
        suma=abs(a.x-vect[x].x)+abs(a.y-vect[x].y);
        if(suma<mejor.num)
        {
            mejor.num=suma;
            mejor.x=vect[x].x;
            mejor.y=vect[x].y;
        }
    }
    return mejor;
}
int main()
{
    cin>>n>>m;
    vector<pos>::iterator it;
    pos aux;
    pos res;
    res.num=0;
    int contador=0;
    int auxf=0;
    int verificaValores = m;
    bool verif[m];
    for(int y=0; y<n; y++)
    {
        for(int x=0; x<n; x++)
        {
            cin>>aux.num;
            aux.x=x;
            aux.y=y;
            vect.push_back(aux);
        }
    }
    for (int i=0; i<n*n; i++)
    {
            //Paso para ahorrar verificacion
            if (verif[ vect[i].num - 1 ] == false){
                verif[ vect[i].num - 1 ] = true;
                verificaValores --;
            }
    }
    if (verificaValores > 0)
    {
        cout << -1 << endl;
    }
    else
    {
    sort(vect.begin(),vect.end(),comp);
    res.x=vect[0].x;
    res.y=vect[0].y;
    for(it=vect.begin(); it!=vect.end(); it++)
    {
        if(auxf!=it->num)
        {
            arr[auxf]=contador;
            auxf=it->num;
        }
        contador++;
    }
    cout<<"VALOR "<<vect[arr[1]].num<<endl;
    for(int x=0; x<=m-2; x++)
    {
        for(int y=arr[x]; y<arr[x+1]; y++)
        {
            aux=Suma(res,x+1);
            res.num+=aux.num;
            res.x=aux.x;
            res.y=aux.y;
        }
    }
        cout<<res.num<<endl;
    }
}
