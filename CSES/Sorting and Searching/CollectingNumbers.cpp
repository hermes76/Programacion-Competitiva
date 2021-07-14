#include <iostream>
#include <algorithm>
using namespace std;

 bool comp(pair<int, int> a, pair<int,int> b)
 {
     if(a.first< b.first)
        return 1;
     return 0;
 }
 int main()
 {
     int n;
     cin>>n;
     pair <int,int> arr[n];
     for(int x=0; x<n; x++)
    {
        cin>>arr[x].first;
        arr[x].second = x;
     }
     sort(arr,arr+n,comp);
    int solve=1;
     for(int x=1; x<n; x++)
     {
         if(arr[x-1].second> arr[x].second)
            solve++;
     }
     cout<<solve;
 }
