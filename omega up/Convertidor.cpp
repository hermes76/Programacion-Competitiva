#include <iostream>
#include <math.h>
using namespace std;

unsigned long long int powt(unsigned long long int x, int y)
{
    unsigned long long int res=x;
    if(y==0)return 1;
    if(y==1)return res;
    for(int z=2; z<=y; z++)res*=x;
    return res;
}
int main()
{
    int caso;
    unsigned long long int paso=0;
    string cad;
    cin>>caso;
    char aux=64;
    int len;
    if(!caso)
    {
        cin>>paso;
        while(paso>0)
        {
            if(paso%26==0){cad+='Z';paso--;}
            else cad+=(aux+paso%26);
            paso/=26;
        }
        for(int x=cad.length()-1; x>=0; x--)cout<<cad[x];

    }
    else
    {
        cin>>cad;
        len=cad.length()-1;
        for(int x=len; x>=0; x--)paso+=powt(26,len-x)*(cad[x]-aux);
        cout<<paso;
    }

}
