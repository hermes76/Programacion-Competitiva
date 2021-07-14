#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int mod=0;
    if(n%2==0)
    {
        n/=2;
        mod++;
    }else{
        n++;
        mod++;
    }
    if(n>=100)
    {
        n/=100;
        mod++;
    }else if (n>=10){
        n/=10;
        mod++;
    }
    if(n%3==0)
    {
        n--;
        mod++;
    }
    cout<<n<<" "<<mod;
}