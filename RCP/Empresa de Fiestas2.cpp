
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct em{
    int a,b;
    vector <int> empleados;
};
int n,m;
int emple[100000];
em part[100000];
bool band;
void rec(int invitado, int organizador, int mine, int maxe)
{
    vector <int>::iterator it;
    for(it=part[invitado].empleados.begin(); it!=part[invitado].empleados.end(); it++)
    {
        if(*it==organizador)band=1;
        if(part[*it].a>=mine and part[*it].a<=maxe)
        {
            emple[*it]++;
            rec(*it,organizador,mine,maxe);
        }
        else if (part[*it].a>maxe) return;

    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int fiesta[m][3];
    int dueno=0;
    for(int x =0; x<n; x++)
    {
        cin>>part[x].a;
        cin>>part[x].b;
    }
    for(int x=1; x<n; x++)
    {
        part[(part[x].b)-1].empleados.push_back(x);
    }
    for(int x=0; x<m; x++)
    {
        cin>>fiesta[x][0];
        cin>>fiesta[x][1];
        cin>>fiesta[x][2];
    }
    for(int x=0; x<n; x++)
    {
        sort(part[x].empleados.begin(),part[x].empleados.end());
    }
    for(int x=0; x<m; x++)
    {
        band=0;
        if(part[dueno].a>=fiesta[x][1] and part[dueno].a<=fiesta[x][2])
        {
            emple[dueno]++;
            rec(dueno,fiesta[x][0]-1,fiesta[x][1],fiesta[x][2]);
        }
        if(band==0 and fiesta[x][0]!=1)
        {
            emple[fiesta[x][0]-1]++;
            rec(fiesta[x][0]-1,fiesta[x][0]-1,fiesta[x][1],fiesta[x][2]);
        }
    }
    for(int x=0; x<n-1; x++)
        {
            cout<<emple[x]<<" ";
        }
    cout<<emple[n-1];
    cout<<endl;
}
