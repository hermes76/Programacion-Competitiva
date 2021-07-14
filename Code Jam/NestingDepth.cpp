#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    string s;
    string res;
    int cuenta=0;
    cin>>n;
    cin.ignore();
    for(int x =0; x<n; x++)
    {
        res="";
        getline(cin,s);
        cuenta=0;
        for(int y=0; y<s.length(); y++)
        {
            if(s[y]!=0)
            {
                for(int z=0; z<s[y]-48-cuenta; z++)
                {
                  res+='(';
                }
                cuenta=s[y]-48;
                res+=s[y];
                if(s[y]>48)
                {
                    if(y+1<s.length())
                    {
                        for(int z =0; z<(s[y]-48)-(s[y+1]-48); z++)
                        {
                            res+=')';
                        }
                    }
                    else{
                            for(int z=0; z<s[y]-48; z++)
                            {
                                res+=')';
                            }
                        }
                }
            }else{
                cuenta=0;
                res+=')';
                res+='0';
            }

        }
        cout<<"Case #"<<x+1<<": "<<res<<endl;
    }
}
