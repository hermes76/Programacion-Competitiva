#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
using namespace std;
vector <ll> vll;

ll solve()
{

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,limitx,limity,cordx,cordy,aux;
    do
    {
        cin>>n;
        if(n!=0)
        {
           cin>>limitx>>limity;
            aux=n;
            while(aux--)
            {
                cin>>cordx>>cordy;
                if(cordx== limitx or cordy == limity)
                {
                    cout<<"divisa\n";
                }else{

                    if(cordy<limity)
                        cout<<"S";
                    else cout<<"N";
                    if(cordx<limitx)
                        cout<<"O";
                    else cout<<"E";
                    cout<<"\n";
                }
            }
        }
    }while(n!=0);
}

