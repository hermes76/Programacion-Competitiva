#include <iostream>
using namespace std;
bool arr[26];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a;
    cin>>a;
    int n;
    cin>>n;
    string res="";
    string aux;
    int k;
    char p=a[a.length()-1];
    bool ban=1;
    for(int x =0; x<n; x++)
    {
        cin>>aux;
        if(aux[0]==p and ban)
        {
            res=aux;
            ban=0;
        }else{
            k=aux[0]-97;
            arr[k]=1;
        }
    }
   
    if(res!="")
    {
        cout<<res;
        k=res[res.length()-1];
        if(arr[k-97]==0)
        {
            cout<<"!";
        }
    }else{
        cout<<"?";
    }
    cout<<endl;
}
