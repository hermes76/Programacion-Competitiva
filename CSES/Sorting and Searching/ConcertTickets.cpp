#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    multiset<int,greater<int>>arr;
    multiset<int,greater<int>>::iterator it;
    cin>>n>>m;
    int parr[m];
    int a;
    for(int x =0; x<n; x++){cin>>a; arr.insert(a);}
    for(int y =0; y<m; y++){cin>>parr[y];}
    for(int x =0; x<m; x++)
    {
        it=arr.lower_bound(parr[x]);
        if(it!=arr.end())
        {
            arr.erase(it);
            cout<<*it<<endl;
        }else
        cout<<-1<<endl;
    }
}
