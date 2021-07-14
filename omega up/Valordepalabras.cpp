#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.ignore();
    string pal;
    int cuenta;
    int letra;
    while(n--)
    {
        getline(cin,pal);
        cuenta=0;
        for(int x=0; x<pal.length(); x++)
        {
            if(pal[x]>96)
            {
                cuenta+=pal[x]-96;
            }else{
                 cuenta+=abs(pal[x]-91);
            }
        }
        cout<<cuenta<<"\n";
    }
}
