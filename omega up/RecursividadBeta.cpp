#include <iostream>
using namespace std;
long long int arr[61];
long long int func(int n)
{
    long long int y;
    if(arr[n] !=0)
    {
        return arr[n];
    }
    if(n <=15)
    {
        arr[n] =n+n*3;
        cout<<arr[n]<<endl;
        return arr[n];
    }else{
            y =func(n-10)*5;
            arr[n] =y;
            cout<<arr[n]<<endl;
        return arr[n];
    }

}
int main()
{
     cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int x =0; x<61; x++)
    {
            arr[x] =0;
    }
    func(n);
}
