#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long int s;
    cin>>s;
    long long int cuenta=s;
    n--;
    long long int mayor=s;
    while(n--)
    {
        cin>>s;
        cuenta=max(s,cuenta+s);
        mayor=max(cuenta,mayor);
    }
    cout<<mayor<<endl;
}
