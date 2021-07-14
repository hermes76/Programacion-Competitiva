#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    int n;
    char b[100005];
    cin>>casos;
    int anterior;
    while(casos--)
    {
        cin>>n;
        for(int x=0; x<n; x++)cin>>b[x];
        cout<<1;
        anterior=1+b[0]-'0';
        for(int x=1; x<n; x++)
        {
            if(b[x]-'0'+1!=anterior)
            {
                cout<<1;
                anterior = b[x]-'0'+1;
            }
            else if (b[x]-'0'!=anterior)
            {
                cout<<0;
                anterior = b[x]-'0';
            }
        }
        cout<<endl;

    }
}
