#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    int A[100000];
    int tam;
    char nums;
    int op;
    cin>>n;
    while(n--)
    {
        cin>>tam;
        for(int x=0; x<tam; x++)
        {
            cin>>nums;
            op=(nums-48)%2;
            if(x==0)
            {
                op=1;
            }
            cout<<op;
            A[x]=(nums-48)-op;
        }
        cout<<"\n";
        for(int x =0; x<tam; x++)
        {
            cout<<A[x];
        }
        cout<<"\n";
    }
}
