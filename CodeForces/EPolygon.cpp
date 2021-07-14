#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    while(n--)
    {
        bool p=0;
        cin>>m;
        char arr[m][m];
        for(int x=0; x<m; x++)
            for(int y =0; y<m; y++)
                cin>>arr[x][y];
        for(int x=0; x<m-1 and !p; x++)
            for(int y=0; y<m-1 and !p; y++)
                if(arr[x][y]=='1')
                    if(arr[x+1][y]=='0' and arr[x][y+1]=='0')
                        p=1;
        if(p)
            cout<<"NO";
        else cout<<"YES";
        cout<<'\n';
    }
}
