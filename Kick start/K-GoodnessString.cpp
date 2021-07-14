#include <iostream>
using namespace std;
int solve(string cad,int n)
{
    int suma=0;
    int index=n-1;
    for(int x=0; x<n/2; x++)
    {
        if(cad[x]!=cad[index])
        {
            suma++;
        }
        index--;
    }
    return suma;
}
int main()
{
    int  t,n,m;
    int res;
    string cad;
    cin>>t;
    for(int x=1; x<=t; x++)
    {
        cin>>n>>m;
        cin.ignore();
        getline(cin,cad);
        res=solve(cad,n);
        cout<<"Case #"<<x<<": ";
        if(res>=m)
            cout<<0;
        else
            cout<<m-res;
        cout<<endl;
    }
}
