#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n,a;
    cin>>n>>a;
    int m=n-n/2;
    n/=2;
    int arr[n];
    int arr2[m];
    vector <int> meet;
    vector <int> midle;
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    for(int x =0; x<m; x++)
    {
        cin>>arr2[x];
    }
    int suma=0;
    int forma=0;
    for(int x =0; x<(1<<n); x++)
    {
        suma=0;
        for(int y=0; y<n; y++)
        {
            if(x&(1<<y)) suma+=arr[y];
        }
        meet.push_back(suma);
    }
    for(int x =0; x<(1<<m); x++)
    {
        suma=0;
        for(int y=0; y<m; y++)
        {
            if(x&(1<<y)) suma+=arr2[y];
        }
        midle.push_back(suma);
    }
    vector <int>::iterator it;
    vector <int>::iterator et;
    sort(meet.begin(),meet.end());
    sort(midle.begin(),midle.end(),greater<int>());
    it=meet.begin();
    et=midle.begin();
    for(it; it!=meet.end(); it++)
    {
        cout<<*it<<endl;
    }
    cout<<"####"<<endl;
    for(et; et!=midle.end(); et++)
    {
        cout<<*et<<endl;
    }
    int nu,num;
    while(it!= meet.end() and et!= midle.end())
    {
        //cout<<*it+*et<<" "<<*it<<" "<<*et<<endl;
        nu=*it;
        num=*et;
        if(nu+num==a){
            et++;
            it++;
            forma++;
        }else if(nu +num>a)
        {
            et++;
        }else{
            it++;
        }
    }
    cout<<forma;
}
