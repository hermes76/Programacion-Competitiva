
#include <bits/stdc++.h>

#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 1000000007
#include <string>
using namespace std;
vector <ll> vll;
map <char,char> mapa;

bool palindrome(char cad[])
{
    for(ll x=0; x<strlen(cad)/2; x++)
    {
        if(cad[x]!= cad[strlen(cad)-1-x])
            return 0;
    }
    return 1;
}
bool mirrored(char cad[])
{
    for(ll x=0; x<strlen(cad)/2; x++)
    {
        if(mapa[cad[x]]==' ' || mapa[cad[x]] != cad[strlen(cad)-1-x])
            return 0;
    }
    if(strlen(cad)%2==1)
    {
        if(mapa[cad[strlen(cad)/2]] == cad[strlen(cad)/2])
        {
            return 1;
        }
        return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll x='A'; x<='Z'; x++)
        mapa[char(x)]= ' ';
    for(ll x=48; x<=57; x++)
        mapa[char(x)]= ' ';
    mapa['A']='A';
     mapa['E']='3';
      mapa['H']='H';
       mapa['I']='I';
       mapa['J']='L';
        mapa['L']='J';
        mapa['M']='M';
         mapa['O']='O';
          mapa['S']='2';
           mapa['T']='T';
            mapa['U']='U';
             mapa['V']='V';
              mapa['W']='W';
               mapa['X']='X';
                mapa['Y']='Y';
                 mapa['Z']='5';
                  mapa['1']='1';
                   mapa['2']='S';
                    mapa['3']='E';
                     mapa['5']='Z';
                      mapa['8']='8';
    char cad[1000000];

    bool palin;
    bool mirror;
    while(scanf("%s",cad)!=EOF)
    {
        palin=palindrome(cad);
        mirror=mirrored(cad);
        printf("%s",cad);
        if(palin ==1 && mirror ==0)
            printf(" -- is a regular palindrome.");
           //out<<" -- is a regular palindrome.";
        else if(mirror ==1 && palin==0)
            printf(" -- is a mirrored string.");
           //out<<" -- is a mirrored string.";
        else if(palin==1 && mirror==1)
             printf(" -- is a mirrored palindrome.");
           // out<<" -- is a mirrored palindrome.";
        else
            printf(" -- is not a palindrome.");
          //out<<" -- is not a palindrome.";
        printf("\n\n");
        //out<<"\n\n";
    }
    //out.close();
}
