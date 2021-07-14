    #include <iostream>
    #include <math.h>
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        int a,b,c;
        int res;
        while(n--)
        {
            cin>>a>>b>>c;
            res=ceil(sqrt((b)*b+(-(abs(c-a)*(-abs(c-a))))));
            cout<<res<<endl;
        }
    }
