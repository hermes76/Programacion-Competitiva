#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,int>> pila;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    pila.push_back({arr[0],1});
    cout<<0<<" ";
    bool bol;
    for(int x =1; x<n; x++)
    {
        if(pila.front().first>=arr[x])
        {
            pila.clear();
            pila.push_back({arr[x],x+1});
            cout<<0<<" ";
        }else
        {
            bol=1;
            do
            {
                if(pila.back().first<arr[x])
                {
                    cout<<pila.back().second<<" ";
                    pila.push_back({arr[x],x+1});
                    bol=0;
                }else{

                pila.pop_back();  
                } 
            }while(bol);
        }
        
    }
}