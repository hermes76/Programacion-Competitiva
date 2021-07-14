#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<21)
    {
        cout<<"fria!";
    }
    else if(n>29)
    {
        cout<<"caliente!";
    }
    else{
        cout<<"tibia";
    }
    cout<<endl;
    if(n<15 or n>34)
    {
        cout<<"RIP escamitas :(";
    }
}