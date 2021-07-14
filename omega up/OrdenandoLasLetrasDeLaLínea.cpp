#include <iostream>
using namespace std;
int arr[26];
int main()
{
    string cad,cad2;
    int indice=0;
    getline(cin,cad);
    char aux;
    for(int x =0; x<cad.length(); x++)
    {
        if(cad[indice]-97<26  && cad[indice]-97>=0){
        arr[cad[x]-97]++;
        }
        indice++;
    }
    indice=0;
    for(int x=0; x<26; x++)
    {
        aux=x+97;
        for(int y =0; y<arr[x];)
        {
            if(cad[indice]-97<26  && cad[indice]-97>=0)
            {
                cad[indice]=aux;
                y++;
            }
            indice++;
        }
    }
   cout<<cad;
}