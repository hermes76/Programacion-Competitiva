#include <iostream>
using namespace std;
int main()
{
    int b;
    for(int x =0; x<4; x++)
    {
        cin>>b;
        if(b%100==0 and b%400==0)
        {
            cout<<29;
        }
        else if(b%100==0 and b%400!=0)
        {
            cout<<28;
        }
        else if(b%4==0)
        {
            cout<<29;
        }else{
            cout<<28;
        }
        if(x<3)
        {
            cout<<" ";
        }
    }
}