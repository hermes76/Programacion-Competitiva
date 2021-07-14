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
    for(int x =0; x<n && alicia<=n-1-bob; x++)
    {
        al=arr[alicia];
        bo=arr[n-1-bob];
        if(al<bo)
        {
            arr[n-1-bob] = al;
            alicia++;
            ayuda=1;
        }else if(al>bo)
        {
            arr[alicia]-=bo;
            bob++;
            ayuda=2;
        }else{
            alicia++;
            bob++;
            ayuda =3;
        }
    }
    if(ayuda==1)
    {
        alicia--;
    }else if(ayuda>=2)
    {
        bob--;
    }
    cout<<alicia<<" "<<bob;
}