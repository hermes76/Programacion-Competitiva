#include <iostream>
using namespace std;
int re(int n)
{
    if(n<=5)
    {
        return 1;
    }return re(n-2)*5;
}
int main()
{
    int n;
    cin>>n;
    cout<<re(n);
}