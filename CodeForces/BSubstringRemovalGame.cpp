#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string arr;
    int cuenta;
    int pod[100];
    int elementos=0;
    while(n--)
    {
        cin>>arr;
        cuenta=0;
        elementos=0;
        for(int x =0; x<arr.length(); x++)
        {
            if(arr[x]=='1')
            {
                cuenta++;
            }else{
                if(cuenta>0)
                {
                    pod[elementos]=cuenta;
                    elementos++;
                }
                cuenta =0;
            }
        }
        pod[elementos]=cuenta;
        elementos++;
        sort(pod,pod+elementos,greater<int>());
        cuenta=0;
        for(int x =0; x<elementos; x+=2)
        {
            cuenta+=pod[x];
        }
        cout<<cuenta<<endl;
    }
}
