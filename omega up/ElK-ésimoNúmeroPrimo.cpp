#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int cuenta=1;
    int num=2;
    if(n==1)
    {
        cout<<2;
    }else{
    while(cuenta<n)
    {
        for(int y =2; y<num; y++)
        {
            if(num%y==0)
            {
                break;
            }
            if(y==num-1){cuenta++;}
        }
        num++;
    }
    cout<<--num;
    }
}