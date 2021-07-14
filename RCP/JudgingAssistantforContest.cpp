#include <iostream>
using namespace std;
bool comp(string a, string b)
{
    int lena=a.length();
    int lenb=b.length();
    bool p;
    for(int x=0; x<lena; x++)
    {
        if(a[x]==b[0])
        {
            p=0;
            for(int y =1; y<min(lena,lenb); y++)
            {
                if(a[x+y]!=b[y])
                {
                    p=1;
                    break;
                }
            }
            if(p==0)
            {
                return 1;
            }
        }
    }
    return 0;
}
bool comp2(string a,string b)
{
    int lena=a.length();
    int lenb=b.length();
    if(lena!=lenb)return 0;
    for(int x=0; x<lena; x++)
    {
        if(a[x]!=b[x])return 0;
    }
    return 1;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string cad;
    string cad2;
    int a,b,c;
    cin.ignore();
    getline(cin,cad);
    cin.ignore();
    getline(cin,cad2);
    cin>>a>>b>>c;
    int n;
    cin>>n;
    string cadenas[n];
    int m;
    bool p;
    for(int x=0; x<n; x++)
    {
        cin.ignore();
        getline(cin,cadenas[x]);
    }
    cin>>m;
    string out[m];
    for(int x=0; x<m; x++)
    {
        cin.ignore();
        getline(cin,out[x]);
    }
    p=comp(cad2,cad);
    if(p==0){cout<<"Compile Error"<<endl; return 0;}
    int len=cad2.length();
    string e="";
    for(int x=0; x<len; x++)
    {
        if(cad2[x]=='.')
        {
            for(x; x<len; x++)
            {
                e+=cad2[x];
            }
        }
    }
    if(e!=".c" && e!=".cpp" && e!=".java" && e!=".py")p=0;
    if(p==0){cout<<"Compile Error"<<endl; return 0;}
    if(a){cout<<"Run-Time Error"<<endl; return 0;}
    if(b<c){cout<<"Time Limit Exceeded"<<endl; return 0;}
    if(n!=m){cout<<"Wrong Answer"<<endl;return 0;}
    for(int x=0; x<n; x++)
    {
        if(cadenas[x]!=out[x]){cout<<"Wrong Answer"<<endl;return 0;}
    }
    cout<<"Correct"<<endl;
    return 0;
}
