#include <iosteeam>
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
bool bfs(int b)
{
    int a;
    while(!cola.empty())
    {
        a=cola.front();
        cola.pop();
        vector <int>::iterator it;
        for(it=arr[a-1].nodos.begin(); it!=arr[a-1].nodos.end();it++)
        {
            if(it==b)
            {
                return 1;
            }
            cola.push(*it);
        }
    }
    return 0;
}
int main()
{
    cin>>n;
    char c;
    int a,b;
    do
    {
        if(c=='P')
        {
            cin>>a;
            cola.push(1);
            BFS(a);
        }else if(c=='D')
        {
            cin>>a>>b;
            arr[a-1].nodos.push_back(b);
        }
    }while(c!='F');
}
