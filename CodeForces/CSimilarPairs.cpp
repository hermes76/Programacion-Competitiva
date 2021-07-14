#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    int pares,impares;
    cin>>n;
    while(n--)
    {
        cin>>m;
        bool act=0;
        int arr[m];
        pares=0;
        impares=0;
        for(int x=0; x<m; x++)cin>>arr[x];
        for(int x=0; x<m; x++)if(arr[x]%2==0)pares++;else impares++;
        if(pares%2==0 and impares%2==0)cout<<"YES";
        else if(pares%2==1 and impares%2==1){
            sort(arr,arr+m);
            for(int x=1; x<m; x++)if(arr[x]-arr[x-1]==1){act=1; break;}
            if(act==1)
                cout<<"YES";
            else
                cout<<"NO";
        }else cout<<"NO";
        cout<<endl;
    }
}
