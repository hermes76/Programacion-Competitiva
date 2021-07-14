#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string cad;
    string res;
    long long int num;
    long long int k;
    int power;
    char aux;
    bool correcto;
    long long int cont;
    while(n--)
    {
        cin>>cad;
        cin>>k;
        correcto=1;
        cont=0;
        res="";
        for(int x=cad.length()-1; x>=0; x--)
        {
            num=1;
            //cout<<cont<<endl;
            if(cad[x]-'0' <= 9)
            {
                num=0;
                power=0;
                for(x; x>=0 and cad[x]-'0' <= 9; x--)
                {
                        num+=(cad[x]-'0')*(pow(10,power));
                        power++;
                }
                x++;
                num--;
            }else aux=cad[x];
                cont+=num;
            //cout<<cont<<" "<<num<<endl;
            if(cont>k)
            {
                correcto=0;
                break;
            }
            for(int y=0; y<num; y++)
            {
                res+=aux;
            }
        }
        if(correcto)
            for(int x=res.length()-1; x>=0; x--)
            {
                cout<<res[x];
            }
        else
        {
            cout<<"unfeasible";
        }
        cout<<endl;
        //cout<<cont<<endl;
    }
}
