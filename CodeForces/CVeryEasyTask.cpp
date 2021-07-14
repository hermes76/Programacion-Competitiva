#include <iostream>
using namespace std;

int main()
{
    int n,m,o,menor,mayor,mm;
    int tiempo=0;
    cin>>n>>m>>o;
    menor=min(m,o);
    mayor=max(m,o);
    tiempo+=menor;
    mm=0;
    n--;
    while(n)
    {
        if(n>=(mayor/menor)+1)
        {

            cout<<n<<endl;
            tiempo+=mayor;
            n=n-((mayor/menor)+1);
            if(mayor>menor)
            {
                mm=mayor%menor;
            }
        }
        else{
                tiempo+=n*menor;
            n=0;
        }
    }
    cout<<tiempo;
}
