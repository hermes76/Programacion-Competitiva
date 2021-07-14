
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,m,r;
    int a,b,c;
    cin>>n>>m>>r>>a>>b>>c;
    double radio1,radio2,radio3,radio4;
    radio1=sqrt((pow(a-n,2))+pow(b-m,2));
    radio2=sqrt(pow(a+c-n,2) +pow(b-m,2));
    radio3=sqrt(pow(a+c-n,2)+pow(b+c-m,2));
    radio4=sqrt(pow(a-n,2)+pow(b+c-m,2));
    cout<<radio1<<endl;
    cout<<radio2<<endl;
    cout<<radio3<<endl;
    cout<<radio4<<endl;
    if(radio1<=r and radio2<= r and radio3<=r and radio4<= r)
    {
        cout<<2;
    }
    else if(radio1==r or radio2==r or radio3==r or radio4== r)
    {
        cout<<1;
    }else{
    cout<<0;}
    cout<<endl;
}
