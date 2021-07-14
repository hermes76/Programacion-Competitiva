#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
        cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    int Asuma=0;
    int Bsuma=0;
    cin>>n;
    if((n+1)%4==0)
    {
        cout<<"YES"<<endl;
        if(n==3)
        {
            cout<<2<<endl<<1<<" "<<2<<endl<<1<<endl<<3;
        }else{
        cout<<(n/2)+1<<endl;
        for(int x =2; x<=n; x+=2)
        {
            if(x<4)
            {
                x--;
            }
            if((x+2)%4==0 and x>5)
            {
                cout<<x+1<<" ";
                Asuma+=x+1;
            }
            else{
                cout<<x<<" ";
                Asuma+=x;
            }
        }
        cout<<endl<<n-(n/2)-1<<endl;
        for(int x =3; x<=n; x+=2)
        {
            if((x+1) %4 ==0 and x>4)
            {
               cout<<x-1<<" ";
               Bsuma+=x+1;
            }
            else{
            cout<<x<<" ";
                Bsuma+=x;
            }
         }
        }
    }else if(n%4==0){
        for(int x =2; x<=n; x+=2)
        {
            Asuma+=x;
        }
        for(int x=1; x<n; x+=2)
        {
            Bsuma+=x;
        }
        int dif = abs(Asuma-Bsuma)/2;
        bool impar=0;
        int B = (n/2)+1;
        int A = (n/2)-1;
        if(dif%2==1)
        {
            dif*=2;
            impar =1;
            A=n/2;
            B=A;
        }
         cout<<"YES"<<endl;
        cout<<A<<endl;
        for(int x =2; x<=n; x+=2)
        {
            if(dif != x)
            {
                cout<<x<<" ";
            }
            if(x+2>dif/2 and impar ==1)
            {
                cout<<dif/2<<" ";
                impar=0;
            }

        }
        cout<<endl<<B<<endl;
        bool una=1;
        dif = abs(Asuma-Bsuma)/2;
        if(dif%2==1)
        {
            impar =1;
        }
        for(int x =1; x<n; x+=2)
        {

            if(impar !=1)
            {
                cout<<x<<" ";
                if(x+2>dif and una ==1)
                {
                    cout<<dif<<" ";
                    una=0;
                }
            }else{
                if(x+2>dif*2 and una ==1)
                {
                    cout<<dif*2<<" ";
                    una=0;
                }
                if(dif!=x)
                {
                    cout<<x<<" ";
                }
            }
        }
    }else{
        cout<<"NO";
    }
}
