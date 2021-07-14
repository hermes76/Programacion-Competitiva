#include <iostream>
using namespace std;

int main()
{
    int casos;
    int ball;
    int mayor;
    int anterior;
    int cuenta;
    int n;
    cin>>casos;
    while(casos--)
    {
        mayor=0;
        cuenta=0;
        anterior=0;
        cin>>n;
        while(n--)
        {
            cin>>ball;

            if(anterior!= ball)
            {
                mayor=max(mayor,cuenta);
                cuenta=0;
                anterior =ball;
            }
            cuenta++;
        }
        mayor=max(mayor,cuenta);
        cout<<mayor<<endl;
    }
}
