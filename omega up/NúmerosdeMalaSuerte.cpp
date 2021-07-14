#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string mala;
    getline(cin,mala);
    bool suerte=0;
    cout<<mala;
    for(int x =mala.length()-1; x>=1; --x)
    {
        if(mala[x]=='3'&& mala[x-1]=='1')
        {
            suerte=1;
            break;
        }
    }
    if(!suerte)
    {
        cout<<" NO";
    }
    cout<<" es de Mala Suerte";
}
