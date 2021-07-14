#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.ignore();
    string arr;
    string aux;
    bool no=0;

    for(int x =0; x<n; x++)
    {
        getline(cin,arr);
        cout<<"Case #"<<x+1<<": ";
        for(int y =0; y<arr.length(); y++)
        {
            if(arr[y]=='4')
            {
                cout<<1;
                no=1;
            }else if(no==1)
            {
                cout<<0;
            }
        }
        cout<<" ";
        for(int y=0; y<arr.length(); y++)
        {
            if(arr[y]== '4')
            {
                arr[y]='3';
            }
        }
        for(int y=0; y<arr.length(); y++)
        {
            cout<<arr[y];
        }
        no=0;
        cout<<endl;
    }

}
