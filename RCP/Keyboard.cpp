#include <iostream>
using namespace std;
char arr[3][9];
int posx[8]={1,1,0,-1,-1,-1,0,1};
int posy[8]={0,1,1,1,0,-1,-1,-1};
bool checar(string a, string b)
{
    int  lena=a.length();
    int lenb=b.length();
    int px;
    int py;
    int valor;
    int aux;
    int auy;
    bool act=0;
    if(lena!=lenb)
    {
        return 0;
    }
    for(int x =0; x<lena; x++)
    {
        valor=a[x]-97;
        py=valor/9;
        valor%=9;
        px=valor;
        act=0;
        if(a[x]!=b[x])
        {

        for(int y=0; y<8; y++)
        {
            aux=px+posx[y];
            auy=py+posy[y];
            if(aux>=0 and aux<9 and auy>=0 and auy<9 and auy*9+aux==b[x]-97)
            {
                act=1;
                break;
            }
        }
        if(act==0)
        {
            return 0;
        }
        }
    }
    return 1;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string a;
    string b;
    int indice=97;
    for(int x =0; x<3; x++)
    {
        for(int y=0; y<9; y++)
        {
            arr[x][y]=indice;
            indice++;
        }
    }
    for(int x =0; x<n; x++)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<1;
        }else if (checar(a,b)==1){
            cout<<2;
        }else{
            cout<<3;
        }
        cout<<endl;
    }
}