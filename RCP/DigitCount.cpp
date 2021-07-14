#include <iostream>
using namespace std;
int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    int res=0;
    int aux;
    for(int x =n; x<=m; x++)
    {
        aux=x;
        while(aux>0)
        {
            if(aux%10==a)
            {
                res++;
            }
            aux/=10;
        }
    }
    cout<<res<<endl;
}
