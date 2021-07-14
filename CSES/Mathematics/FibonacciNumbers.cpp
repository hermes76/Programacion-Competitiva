#include <iostream>
using namespace std;

int get_fibonacci_huge_fast(long long n)
{
    if(n<2)
        return n;
    if(n%39234468330==0)
        return 0;
    long long a=0, b=1, c=0;
    for(int x =0; x<n%39234468330-1; x++)
    {
        c=a+b;
        c%=1000000007;
        a=b;
        b=c;
    }
    return c;
}
int main() {
    long long n;
    cin >> n;
      cout<<n%39234468330<<endl;
    cout<<get_fibonacci_huge_fast(n)%1000000007<<' ';
}
