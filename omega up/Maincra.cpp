#include <iostream>
#define ll long long int
using namespace std;
int main()
{
  int n;
  int m;
  cin>>n;
  int arr[n];
  for(int x=0; x<n; x++)cin>>arr[x];
  cin>>m;
  ll maximo=0;
  ll res=0;
  for(int x=0; x<m; x++)maximo+=arr[x];
  res= maximo;
  for(int x =m; x<n; x++)
  {
      maximo-=arr[x-m];
      maximo+=arr[x];
      res=max(maximo, res);
  }
  cout<<res;
}
