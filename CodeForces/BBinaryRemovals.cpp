#include <iostream>
using namespace std;
bool solve()
{
    string cad;
    cin>>cad;
    int n= cad.length();
    int mayores=0;
    bool valido=1;
    mayores=min(cad[0]-'0', cad[1]-'0');
    for(int x=1; x<n; x++)
        if(cad[x-1]==cad[x] and cad[x-1]=='1' and mayores<1)
            mayores=1;
        else if (mayores==1 and cad[x-1]== cad[x] and cad[x-1]=='0')
            return 0;
    return 1;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        if(solve()==1)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<"\n";
    }
}
