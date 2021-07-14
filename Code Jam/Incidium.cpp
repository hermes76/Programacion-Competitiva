#include <iostream>
using namespace std;
int m;
int arr[50][50];
int sum;
int acabar;
int pos;
void sudoku(int posy, int posx)
{
    if(posx>=m)
    {
        posy++;
        posx=0;
    }
    if(posy>=m && acabar==0)
    {
        acabar=1;
        cout<<"Case #"<<pos+1<<": POSSIBLE"<<endl;
        for(int x=0; x<m; x++)
        {
            for(int y =0; y<m; y++)
            {
                cout<<arr[x][y]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(acabar==0)
    {
        if(posx!=posy)
        {
            int acces;
            int acces2=0;
            for(int x =1; x<=m and acabar==0; x++)
            {
                acces=1;
                for(int y =0; y<m && acabar==0; y++)
                {
                    if(x==arr[posy][y])
                    {
                        acces=0;
                        break;
                    }
                    if(x==arr[y][posx])
                    {
                        acces=0;
                        break;
                    }
                }
                if(acces==1)
                {
                    acces2=1;
                    arr[posy][posx]=x;
                    sudoku(posy,posx+1);
                    arr[posy][posx]=x;
                }
                arr[posy][posx] =0;
            }
        }else{
            sudoku(posy,posx+1);
            return;
        }
    }else{
        return;

    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int div;
    int h;
    int acc;
    for(int x=0; x<n; x++)
    {
        cin>>m>>sum;
        acabar=0;
        pos=x;
        h=1;
        while(h<=m && acabar==0)
        {
            acc=1;
            div = sum;
            arr[0][0]=h;
            div-=h;
            for(int y=1; y<m; y++)
            {
                arr[y][y]=div/(m-y);
                div-=div/(m-y);
                if(arr[y][y]==0 or arr[y][y]>m)
                {
                    acc=0;
                    break;
                }
            }
            if(m<=sum && (float)sum/m <=m and acc and  div==0)
            {
                sudoku(0,1);
            }
            h++;
        }
        if(acabar==0)
        {
            cout<<"Case #"<<x+1<<": IMPOSSIBLE"<<endl;
        }
    }
}
