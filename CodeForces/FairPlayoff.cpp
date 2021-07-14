#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000007
using namespace std;
vector <ll> vll;

string solve()
{
    int arr[4];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    int mayor1=0,mayor2=0;
    int pos1,pos2;
    for(int x=0; x<4; x++)
    {
       if(mayor1<arr[x])
       {
           pos1=x;
           mayor1=arr[x];
       }
    }
     for(int x=0; x<4; x++)
     {

        if(arr[x]!=mayor1 && mayor2 <arr[x])
        {
            pos2=x;
            mayor2=arr[x];
        }

     }
     if(pos2>pos1)
        swap(pos1,pos2);

  //  cout<<endl<<pos1<<" "<<pos2<<endl;
     if(pos1==1)
        if(pos2==0)
            return "NO";
     if(pos1==3)
        if(pos2==2)
            return "NO";
     return "YES";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        cout<<solve()<<endl;
    }
}
