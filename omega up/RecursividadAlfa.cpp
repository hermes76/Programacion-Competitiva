#include <iostream>
using namespace std;
long long int arr[1000];
long long int func(int n)
{
    long long int y;
    if(arr[n] !=0)
    {
        return arr[n];
    }
    if(n <50)
    {
        arr[n] =2;
        return 2;
    }else{
            y =func(n-1)+(func(n-5)*2);
            arr[n] =y;
        return arr[n];
    }

}
int main()
{
     cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int x =0; x<1000; x++)
    {
            arr[x] =0;
    }
    cout<<func(n);
}
