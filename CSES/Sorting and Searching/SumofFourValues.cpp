/*#include <iostream>
#include <algorithm>*/
#include <bits/stdc++.h>
using namespace std;
struct p
{
    int x,y;
};
int i1,i2,i3,i4;
long long suma1,suma2;
bool comp(p a,p b)
{
    return a.x<b.x;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    p arr[n];
    for(int x =0; x<n; x++)
    {
        cin>>arr[x].x;
        arr[x].y=x;
    }
    sort(arr,arr+n,comp);
    for(i1=0,i4=n-1; i1<i4;)
    {
        suma1=arr[i1].x+arr[i4].x;
        suma2=0;
        for(i2=0, i3=n-1; i2<i3;)
        {
            if(i2!= i1 and i2!= i4 and i3!= i1 and i3!= i4)
            {
                suma2=arr[i2].x+arr[i3].x;
                if(suma2+suma1==m)
                {
                    cout<<arr[i1].y+1<<" "<<arr[i2].y+1<<" "<<arr[i3].y+1<<" "<<arr[i4].y+1;
                    return 0;
                }
                else if(suma2+suma1<m)i2++;
                else if(suma2+suma1>m) i3--;
            }else{
                if(i2==i1 or i2 == i4)
                {
                    i2++;
                }
                if(i3==i1 or i3 == i4)
                {
                    i3--;
                }
            }
        }
        cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<suma1<<" "<<suma2<<" "<<suma1+suma2<<endl;
        if(suma2+suma1>m)i4--;
        else if(suma2+suma1<m)i1++;
    }
    cout<<"IMPOSSIBLE";
}
