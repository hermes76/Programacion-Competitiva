
#include <iostream>
using namespace std;
struct drug
{
    string s;
    int rec;
    int fin;
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    while(n--)
    {
        cin>>a>>b;
        drug arr[a];
        for(int x =0; x<a; x++)
        {
            cin>>arr[x].s;
            cin>>arr[x].rec;
            arr[x].fin=arr[x].rec;
        }
        int x=0;
        while(x<b)
        {
            for(int y=0; y<a-1 and x<b; y++)
            {
                while(arr[y].fin<=arr[y+1].fin and x<b)
                {
                    cout<<arr[y].fin<<" "<<arr[y].s<<endl;
                    arr[y].fin+=arr[y].rec;
                    x++;
                }
            }
            if(x<b)
            {
                cout<<arr[a-1].fin<<" "<<arr[a-1].s<<endl;
                arr[a-1].fin+=arr[a-1].rec;
                x++;
            }
        }

    }
}
