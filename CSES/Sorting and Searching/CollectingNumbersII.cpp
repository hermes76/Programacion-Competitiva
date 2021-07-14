#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a,pair<int, int > b)
{
    if(a.first<b.first)
        return 1;
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    pair<int,int> arr[n];
    int indices[n];
    for(int x=0; x<n; x++){cin>>arr[x].first; arr[x].second=x; indices[x]=arr[x].first;}
    sort(arr,arr+n,comp);
    int solve=1;
    for(int x=1; x<n; x++)
    {
        if(arr[x-1].second> arr[x].second)
            solve++;
    }
    cout<<solve<<endl;
    int a,b,c;
    int primero,segundo;
    for(int x=0; x<m; x++)
    {
        cin>>a>>b;
        cout<<arr[indices[a-1]-1].second<<" -> "<<arr[indices[b-1]-1].second<<endl;
        segundo=arr[indices[a-1]-1].second;
        primero=arr[indices[b-1]-1].second;


        c=arr[indices[a-1]-1].second;
        arr[indices[a-1]-1].second=arr[indices[b-1]-1].second;
        arr[indices[b-1]-1].second=c;

        c=indices[a-1];
        indices[a-1]=indices[b-1];
        indices[b-1]=c;
        cout<<arr[indices[a-1]-1].second<<" -> "<<arr[indices[b-1]-1].second<<endl;
        if(indices[a-1]-2>=0)
        if(arr[indices[a-1]-2].second < arr[indices[a-1]-1].second and arr[indices[a-1]-2].second>= segundo)
        {
            solve--;
        }else solve++;

        if(indices[b-1]-2>=0)
         if(arr[indices[b-1]-2].second < arr[indices[b-1]-1].second or arr[indices[b-1]-2].second>= primero)
        {
            solve--;
        }else solve++;
        cout<<solve<<endl;
    }

}
