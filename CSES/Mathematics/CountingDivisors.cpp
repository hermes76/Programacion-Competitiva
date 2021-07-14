#include <iostream>
#include <map>
#include <vector>
using namespace std;
int counting(int num)
{
    map <int,int > mapa;
    vector <int> vect;
    for(int x=2; x*x<= num;x++)
    {
        while(num%x==0)
        {
            if(mapa[x]<0){
                mapa[x]=0;
            }
            mapa[x]++;
            vect.push_back(x);
            num/=x;
        }
    }
    if(num>1)
    {
        mapa[num]++;
        vect.push_back(num);
    }
    int valor=1;
    int ant=0;
     for (auto i = vect.cbegin(); i != vect.cend(); ++i) 
     {
         if(ant==*i)
         {
             continue;
         }
         ant=*i;
         valor*=mapa[*i]+1;
     }
    return valor;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    while(n--)
    {
        cin>>a;
        cout<<counting(a)<<endl;
    }
}