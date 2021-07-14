#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    float x;
    cin>>x;
    if(x<6)
        cout<<"NA";
    else if(x<7.5)
        cout<<"S";
    else if (x<9)
        cout<<"B";
    else cout<<"MB";
}
