#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s,h,aux;
    cin>>s>>h;
    aux='a';
    aux+=h;
    long long int a,res;
    a=1;
    res=0;
    for(int x=0; x<s.length(); x++)
    {
        int y=0;
        for(y; y<h.length(); y++)
        {
            if(h[y]!=s[x]) break;
            if(y+1==h.length())
            {
                x+=y;
                res++;
            }
        }
    }
    cout<<res;
}
