#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int n=0;
    for(int x=1; x<a; x++)
    {
        if(x%2==1)
        {
            n+=x;
        }
    }
    
}