#include <iostream>
#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;
long long int counting(long long int num)
{
    long long int aux=num;
    unordered_map <long long int,long long int > mapa;
    vector <long long int> vect;
    for(long long int x=2; x*x<= num;x++)
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
    long long int p=0;
     for (auto i = vect.cbegin(); i != vect.cend(); ++i)
     {
         if(*i==p)
         {
            continue;
         }
        valor*=(pow(*i,mapa[*i]+1)-1)/(*i-1);
        p=*i;
     }
     valor-=aux;
    return valor;
}
string solve(long long int s)
{
    long long int sum=counting(s);
    if(sum<s)return "deficient";
    if(sum==s)return "perfect";
    return "abundant";
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    long long int s;
    cin>>n;
    while(n--){cin>>s; cout<<solve(s)<<endl;}
}
