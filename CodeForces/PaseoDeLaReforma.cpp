#include <iostream>
using namespace std;

int main()
{
   long long int n,solve, edificios,cont,anterior;
   cin>>n>>anterior;
   n--;
   cont=1;
   solve=1;
   while(n--)
   {
       cin>>edificios;
       if(anterior>edificios)
       {
           cont++;
           solve=max(solve,cont);
       }
       else cont=1;
       anterior=edificios;
   }
   cout<<solve;
}
