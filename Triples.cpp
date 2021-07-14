#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<long long int> cola;
    long long int  a;
    for(int x =0; x<n; x++)
    {
        cin>>a;
        if(a%3==0)
        {
            cola.push(x+1);
        }
    }
    if(cola.empty())
    {
        cout<<"No hay triples.";
        return 0;
    }
    cout<<cola.size()<<'\n';
    while(!cola.empty())
    {
        cout<<cola.front()<<' ';
        cola.pop();
    }
}
