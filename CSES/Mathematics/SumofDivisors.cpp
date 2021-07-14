#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int counting(long long int num)
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
    long long int valor=1;
    int p=0;
     for (auto i = vect.cbegin(); i != vect.cend(); ++i) 
     {
         if(*i==p)
         {
            continue;
         }
        valor*=(pow(*i,mapa[*i]+1)-1)/(*i-1);
        valor%=1000000007;
        p=*i;
     }
    return valor;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long intint n;
    cin>>n;
    long long int valor=0;
    for(n; n>0; n--)
    {
        valor+= counting(n);
        valor%=1000000007;
    }
    cout<<valor;
}