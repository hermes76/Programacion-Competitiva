#include <iostream>
using namespace std;

int main()
{
    int n,m,f;
    cin>>n;
    int nums;
    long long int sum;
    while(n--)
    {
        cin>>m>>f;
        sum=0;
        for(int x=0; x<m; x++){cin>>nums;sum+=nums;}
        if(sum==f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
