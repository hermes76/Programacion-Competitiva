#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map <string,int>mapa;
int ABC[27];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long int res=0;
    cin>>n;
    string arr[n];
    for(int x =0; x<n; x++){cin>>arr[x];mapa[arr[x]]++;}
    for(int x =0; x<n; x++)
    {
        ABC[arr[x][0]-65]++;
    }
    for(int x =0; x<n; x++)
    {
        res+=(ABC[arr[x][0]-65]-1)-(mapa[arr[x]]-1);
    }
    cout<<res<<endl;

}
