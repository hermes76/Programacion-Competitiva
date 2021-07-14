#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a , string b)
{
    if(a[a.length()-1]>=b[b.length()-1])
    {
        return(a>b);
    }
    return(b<a);


}
int main()
{
    int n;
    cin>>n;
    string cads[n];
    vector <string> arr;
    for(int x =0; x<n; x++)
    {
        cin>>cads[x];
    }
    for(int x =0; x<n; x++)
    {
        
        sort(cads[x].begin(),cads[x].end(),greater<char>());
        arr.push_back(cads[x]);
    }
    sort(arr.begin(),arr.end(),compare);
    for(int x=0; x<n; x++)
    {
        cout<<arr[x];
    }


}