#include <iostream>
using namespace std;

int main()
{
    int n,x1,y1,x2,y2,solu;
    cin>>n;
    while(n--)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1!=x2)
        {
            solu=abs(x1-x2);
            if(y1!=y2)
                solu+=abs(y1-y2)+2;
        }else solu=abs(y2-y1);
        cout<<solu<<endl;

    }

}
