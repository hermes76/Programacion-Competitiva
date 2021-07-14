#include <iostream>
using namespace std;
long long int arr[1000001];
void Fact()
{
    arr[0]=1;
    for(int x =1; x<=1000000; x++)
    {
        arr[x]=(arr[x-1]*x)%1000000007;
    }
}
int BC(int a,int b)
{
    long long int div;
    div=(arr[a-b]*arr[b])%1000000007;
    cout<<div<<" "<<arr[a]<<endl;
    cout<<arr[a]/div<<endl;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    Fact();
    while(n--)
    {
        cin>>a>>b;
        BC(a,b);
    }
}
