#include <bits/stdc++.h>
#define i int
using namespace std;
i main()
{
    i n,b;
    cin>>n;
    i a[n];
    long long c=0;
    for(i x=0; x<n; x++)cin>>a[x];
    sort(a,a+n);
    i m=a[n/2];
    for(i x=0;x<n;x++)
    {
        b=a[x];
        if(m!=b)
        {
            c+=abs(b-m);
        }
    }
    cout<<c;
}
