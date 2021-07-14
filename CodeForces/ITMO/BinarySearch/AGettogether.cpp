#include <iostream>
#include <iomanip>
using namespace std;
bool isgood(pair< double, double> personas[],int n, double t)
{
    double mini = 1e9, maxi = -1e9;
    for(int x=0; x<n; x++)
    {
        double a = personas[x].first - t*personas[x].second;
        double b = personas[x].first + t*personas[x].second;
        mini = min(mini, b);
        maxi = max(maxi, a);
    //    cout<<endl<<a<<" "<<b;
    }
    //cout<<endl<<endl<<maxi<<" "<<mini;
    if(maxi<=mini)
        return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    pair<double,double> personas[n];
    for(int x=0; x<n; x++)cin>>personas[x].first>>personas[x].second;
    double k=0;
    for(double x=(1e9)/2;x>=0.0000001; x/=2)
    {
       while(!isgood(personas,n,k+x))k+=x;
    }
    cout<<setprecision(7)<<k;
}
