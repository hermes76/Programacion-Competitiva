#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int cuenta=0;
    int proc=1;
    while(proc<n)
    {
        proc*=2;
        cuenta++;
    }
    cout<<cuenta;
}