#include <iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int res1,res2,limite;
    int cuenta=0;
    res1=res2=limite=0;
    cout<<endl;
    for(int x=0; x<m; x++)
    {
        res1|=1<<x;
        limite |=1<<x;
    }
    limite<<=n;
    res2+=res1+k;

    while(res2< limite and cuenta != m)
    {
        cuenta=0;
        for(int x=1; x<limite; x=x<<1)
            if(res2&(x))
                cuenta++;
        res1++;
        res2++;

    }
    if(cuenta==n)
        cout<<"YES"<<endl<<res2<<" "<<res1<<endl;
    else cout<<"NO";
}
