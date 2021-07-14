#include <iostream>
using namespace std;

int abc[26];
int main()
{
    string line;
    getline(cin,line);
    int pos;
    int impar=0;
    for(int x =0; x<line.length(); x++)
    {
        pos=line[x]-65;
        abc[pos]++;
    }
    for(int x =0; x<26; x++)
    {
        if(abc[x]%2==1)
        {
            impar++;
        }
    }
    if((line.length()%2== 0&& impar>0 )|| (line.length()%2==1 && impar>1))
    {
            cout<<"NO SOLUTION";
    }else{
        pos=-1;
        char n;
        for(int x =0; x<26; x++)
        {
            if(abc[x]%2&&pos==-1)
            {
                pos=x;
            }
            for(int y =0; y<abc[x]/2;y++)
            {
                n=65+x;
                cout<<n;
            }
            abc[x]/=2;
        }

        if(pos!=-1)
        {
            n=pos+65;
            cout<<n;
        }
        for(int x=25; x>=0; x--)
        {
            for(int y =0; y<abc[x];y++)
            {
                n=65+x;
                cout<<n;
            }
        }
    }
}
