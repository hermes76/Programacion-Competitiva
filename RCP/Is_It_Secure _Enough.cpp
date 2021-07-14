#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string cad;
    int cuenta;
    int tam;
    bool conts[5];
    bool num;
    bool novalido;
    for(int p=1; p<=n; p++)
    {
        cin>>cad;
        for(int x=0; x<5; x++)
        {
            conts[x]=0;
        }
        num=0;
        novalido=0;
        cuenta=0;
        tam=cad.length();
        if(tam>=10)conts[4]=1;
        char car[8]={'.','#','$','%','/','(','&',')'};
        int cuenta=0;
        cad+='A';
        for(int x=0; x<tam; x++)
        {
            if(isupper(cad[x]) && conts[1]==0)conts[1]=1;
            if(islower(cad[x]) && conts[0]==0)conts[0]=1;
            if(cad[x]-47 <=10 && cad[x]-47>0)
            {
                num=1;
                if(cad[x+1]-47<=10 && cad[x+1]-47>0)
                {
                    novalido=1;
                }
            }
            if(conts[3]==0)
            {
                for(int y=0; y<8; y++)
                {
                    if(cad[x]==car[y])
                    {
                        conts[3]=1;
                        break;
                    }
                }
            }
        }
    if(num)
    {
        if(novalido==0)
        conts[2]=1;
    }
    for(int x=0; x<5; x++)
    {
        cuenta+=conts[x];
        cout<<conts[x]<<" ";
    }
    if(cuenta==5)
        cout<<"Assertion number #"<<p<<": Strong";
    else if(cuenta==4)
        cout<<"Assertion number #"<<p<<": Good";
    else if(cuenta==3)
        cout<<"Assertion number #"<<p<<": Weak";
    else
        cout<<"Assertion number #"<<p<<": Rejected";
    cout<<'\n';
    }
}
