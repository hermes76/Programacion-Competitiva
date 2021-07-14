#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    string res;
    string cad;
    for(int x =0; x<n; x++)
    {
        int m;
        cin>>m;
        for(int y=0; y<m; y++)
        {
            cin>>cad;
            for(int z=0; z<cad.length(); z++)
            {
                if(cad[z]!='*' or res[z]==cad[z])
                {
                    res+=cad[z];
                }
            }
        }
    }
    cout<<res;
}