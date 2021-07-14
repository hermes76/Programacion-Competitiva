#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector pair<int,int>lropes;
int lowerbound(int q, int n)
{
    int l,r,m;
    r=n-1;
    while(r<l+1)
    {
        m=(l+r)/2;
        if(lropes[m]>q)
            r=m;
        else
            l=m;
    }
    return r;
}
int uperbound(int q, int n)
{
    int l,r,m;
    r=n-1;
    while(r<l+1)
    {
        m=(l+r)/2;
        if(lropes[m]>q)
            r=m;
        else
            l=m;
    }
    return r;
}
int solve(int q, int n)
{

}
int main()
{
    int ropes,queries,q;
    pair < int , int > dupla;
    cin>>ropes>>queries;
    for(int x=0; x<ropes; x++)
    {
        cin>>dupla.first>>dupla.second;
        lropes.push_back(dupla);
    }
    sort(lropes.begin(),lropes.end());

    for(int x=0; x<queries; y++)
    {
        cin>>q;
        solve(q,ropes);
    }
}
