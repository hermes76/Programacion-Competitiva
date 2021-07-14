#include <iostream>
using namespace std;

long long int funcion(long long int n)
{
    if(n%2 !=0)
    {
        n=(n*3)+1;
    }else{
        n /=2;
    }
    return n;
}
int main()
{
    long long int n;
    cin>>n;
    if(n != 1)
    {
        do
        {
             cout<<n<<" ";
            n = funcion(n);
        }while(n !=1);
    }
     cout<<n<<" ";
}
