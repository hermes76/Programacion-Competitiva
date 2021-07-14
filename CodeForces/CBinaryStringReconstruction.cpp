#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        bool p =1;
        string w;
        string s;
        int x;
        int len;
        cin>>s>>x;
        len =s.length();
        for(int i=0; i<len; i++)w+='1';
        for(int i=0; i<len; i++)
        {
            if(s[i]==0)
            {
                if(i+x<len)w[i+x]='0';
                if(i-x>=0)w[i-x]='0';
            }
        }
        /*for(int i=0; i<len; i++)
        {
            bool b,c;
            b=0;c=0;
                if(i+x<len)
                {
                    if(s[x]!=w[x+i])b=1;
                }
                if(i-x>=0)
                {
                    if(s[x]!=w[i-x])c=1;
                }
                if(b&c){p=0;break;}
        }*/
        if(p)
        for(int x =0;x=len; x++)cout<<w[x];
        else
        cout<<-1;
        cout<<endl;

    }
}
