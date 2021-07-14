#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x];
    }
    int alicia=0;
    int bob=0;
    int al;
    int bo;
    int ayuda=0;
    int pos=0;
    for(int x =0; x<n && alicia<=n-1-bob; x++)
    {
        al=arr[alicia];
        bo=arr[n-1-bob];
        cout<<pos<<bob<<endl;
        if(al<bo)
        {
            arr[n-1-bob] = al;
            alicia++;
        }else if(al>bo)
        {
            arr[alicia]-=bo;
            bob++;
        }else{
            alicia++;
            bob++;
        }
         if(bob==pos)
        {
            ayuda=1;
        }
        pos=bob;
    }
    if(ayuda==1)
    {
        alicia--;
    }else if(ayuda==0){
        bob--;
    }
    cout<<alicia<<" "<<bob;
}