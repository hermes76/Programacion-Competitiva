#include <iostream>
using namespace std;
bool check(string s)
{
    int len=s.length()-1;
    int ini=0;
    while(ini<=len)
    {
        if(s[ini]!=s[len])return 0;
        ini++;
        len--;
    }
    return 1;
}
int main()
{
    string s,p;
    getline(cin,s);
    int len=s.length()-1;
    p=s;
    char aux;
    for(int x =0; x<s.length(); x++)
    {
        if(check(p)){cout<<"Circular"; return 0;}
        aux =p[0];
        for(int y=1; y<=len; y++)
        {
            p[y-1]=p[y];
        }
        p[len]=aux;
    }
    cout<<"No Circular";
}
