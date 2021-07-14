#include <iostream>
using namespace std;
int main()
{
   string a;
   getline(cin,a);
   char actual='0';
   int cuenta=0;
   for(int x =0; x<a.length() and cuenta<7; x++)
   {
       if(a[x]=='1')
       {
           if(actual=='0')
            cuenta=0;
           actual='1';
           cuenta++;
       }else{
           if(actual=='1')
            cuenta=0;
            actual='0';
            cuenta++;
       }
   }
   if(cuenta==7)
    cout<<"YES";
   else cout<<"NO";
}
