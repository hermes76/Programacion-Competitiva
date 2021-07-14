//#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("A.txt","r",stdin);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int x =0; x<n; x++)cin>>arr[x];
    int suma=0;
    int res=0;
    int indice1=0;
    int indice2=0;
    for(indice2; indice2<n;)
    {
        if(suma+arr[indice2]<=m){suma+=arr[indice2]; indice2++;}
        else break;
    }
    while(indice1<n)
    {
        if(suma==m)res++;
        if((indice2<n) and (suma+arr[indice2]<=m)){suma+=arr[indice2]; indice2++;}
        else {suma-=arr[indice1]; indice1++;}
    }
    cout<<res;
}
