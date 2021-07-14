#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<int> cola;
    int aux=0;
    int aux2=0;
    for(int fibo=1; fibo<n;)
    {
        aux2=fibo;
        fibo+=aux;
        cola.push(fibo);
        aux=aux2;
    }
    for(int x=1; x<n; x++)
    {
        if(!cola.empty())
        {
            if(cola.front()==x)
            {
                cola.pop();
            }
            else
            {
                cout<<x<<" ";
            }
        }
    }

}
