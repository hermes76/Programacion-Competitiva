
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,m,r;
    int a,b,c;
    cin>>n>>m>>r>>a>>b>>c;
    float radio1,radio2,radio3,radio4;
    radio1=sqrt(((a-n)*(a-n))+((b-m)*(b-m)));
    radio2=sqrt(((a+c-n)*(a+c-n))+((b-m)*(b-m)));
    radio3=sqrt(((a+c-n)*(a+c-n))+((b+c-m)*(b+c-m)));
    radio4=sqrt(((a-n)*(a-n))+((b+c-m)*(b+c-m)));
    /*cout<<radio1<<endl;
    cout<<radio2<<endl;
    cout<<radio3<<endl;
    cout<<radio4<<endl;*/
    if(radio1<r or radio2<r or radio3<r or radio4<r)
    {
        cout<<2;
    }
    else if(radio1==r or radio2==r or radio3==r or radio4== r)
    {
        cout<<1;
    }else{
        cout<<0;
    }
    cout<<endl;
}
