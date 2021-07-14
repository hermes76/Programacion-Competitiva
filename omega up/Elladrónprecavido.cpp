#include <iostream>
using namespace std;

int main()
{
    int n,k;
    int num[n];
    int res[n];
    int local[n];
    int maximo=0;
    for(int x =0; x<n; x++)
    {
        cin>>num[x];
    }
    for(int x =0; x<n; x++)
    {
        for(int y =x+2; y<n; y++)
        {
            res[y%2]+=num[x];
        }

    }

}
