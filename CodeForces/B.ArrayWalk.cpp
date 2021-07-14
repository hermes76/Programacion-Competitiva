#include <iostream>
using namespace std;

int S(int arr[], int a,int b, int c, int indicea)
{
    int cuenta=arr[0];
    int suma;
    int indice=1;
    bool z;
    while(b--)
    {
        suma=cuenta;
        cuenta+=arr[indice];
        if(indice>0 and z==0 and c>0)
        {
            if(indice==indicea)
            {
                indice--;
                z=1;
                c--;
            }else{
                if(indice<a)
                {

            indice++;}
            }
        }else{
            z=0;
            if(indice<a)
            {
                indice++;
            }
        }
    }
    return cuenta;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b,c,indice,suma,mayor=0;
    for(int x=0; x<n; x++){
        cin>>a>>b>>c;
        mayor=0;
        int arr[a];
        for(int y=0; y<a; y++)
        {
            cin>>arr[y];
            if(y>0)
            {
                suma=arr[y-1]+arr[y];
                if(mayor<suma and y<=b)
                {
                    indice=y;
                    mayor=suma;
                }
            }
        }
        cout<<S(arr,a,b,c,indice)<<endl;
    }
}
