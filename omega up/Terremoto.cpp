#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct K
{
    vector <int> nodos;
};
int n;
queue <int> cola;
K arr[10000];
bool ab[10000];
bool bfs(int b)
{
    int a;
    while(!cola.empty())
    {
        a=cola.front();
        cola.pop();
        vector <int>::iterator it;
        for(it=arr[a].nodos.begin(); it!=arr[a].nodos.end();it++)
        {
            if(*it==b)
            {
                return 1;
            }
            if(ab[*it]==0)
            {
                ab[*it]=1;
                cola.push(*it);
            }
        }
    }
    return 0;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    char c;
    int a,b;
    do
    {
        cin>>c;
        if(c=='P')
        {
            cin>>a;
            a--;
            for(int x =0; x<n; x++)
            {
                ab[x]=0;
            }
            if(a!=0)
            {
                cola.push(0);
                cout<<bfs(a)<<endl;
            }else{
            cout<<1<<endl;}
        }else if(c=='D')
        {
            cin>>a>>b;
            a--;
            b--;
            arr[a].nodos.push_back(b);
            arr[b].nodos.push_back(a);
        }
    }while(c!='F');
}
