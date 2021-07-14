#include <iostream>
#include <algorithm>
using namespace std;
int arr[26];
 int letra[26];
int main()
{
    string cad;
    getline(cin,cad);
    int diferencia;
    int aux;
    for(int x =0; x<cad.length(); x++)
    {
        diferencia = cad[x]-97;
        arr[diferencia] +=1;
        letra[diferencia] = diferencia+97;

    }
    for(int x =0; x<26; x++)
    {
        for(int y=1; y<26; y++)
        {
            if(arr[y-1]>arr[y])
            {
                aux=arr[y-1];
                arr[y-1] = arr[y];
                arr[y] =aux;
                aux=letra[y-1];
                letra[y-1] = letra[y];
                letra[y] = aux;
            }else if(arr[y-1]==arr[y] and letra[y-1]>=97)
               {
                    if(letra[y-1]<letra[y])
                       {
                           aux=arr[y-1];
                            arr[y-1] = arr[y];
                            arr[y] =aux;
                            aux=letra[y-1];
                            letra[y-1] = letra[y];
                            letra[y] = aux;
                       }
               }
        }
    }
    char t;
    for(int x =0; x<26; x++)
    {
        for(int y =0; y<arr[26-x-1]; y++)
        {
            t=letra[26-x-1];
            if(t >=97)
            {
                cout<<t;
            }
        }
    }
    cout<<endl;
}
