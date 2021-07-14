#include <iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    char car;
    for(int x =0;x<a.length(); x++)
    {
        car=a[x];
        switch(tolower(a[x]))
        {
            case 'o':
            car='0';
            break;
            case 'i':
            car='1';
            break;
            case 'z':
            car='2';
            break;
            case 'e':
            car='3';
            break;
            case 'a':
            car='4';
            break;
            case 's':
            car='5';
            break;
            case 'g':
            car='6';
            break;
            case 't':
            car='7';
            break;
            case 'b':
            car='8';
            break;
        }
        cout<<car;
        
    }
}