#include <iostream>
using namespace std;
string cad;
bool comp(int x, int x2)
{
    if(cad[x]=='A' and cad[x2]=='B')return 1;
    if(cad[x]=='B' and cad[x2]=='B')return 1;
    return 0;
}
int main()
{
    int n,iz,de,len,res;
    cin>>n;
    while(n--)
    {
        res=0;
        cin>>cad;
        len=cad.length();
        iz=0;
        de=1;
        while(de<len)
        {
            if(comp(iz,de))
            {
                res++;
                iz-=1;
                de++;
                if(iz<0)
                {
                    iz=de;
                    de++;
                }
            }
            else
            {
                iz=de;
                de++;
                for(int x=iz; x<len-1; x++)
                {
                    //cout<<iz<<" "<<de<<endl;
                    if(comp(x,x+1))
                    {
                        iz=x;
                        de=x+1;
                    }
                }
            }
        }
        cout<<len-res*2<<'\n';
    }
}
