#include <bits/stdc++.h>
#include <windows.h>
#define MAXN 1000
#define MINN 2
#define MAXINPUT 10000
#define MININPUT 2
#define COLOR_BLUE	              1
#define COLOR_GREEN	              2
#define COLOR_CYAN	              3
#define COLOR_RED	              4
#define COLOR_MAGENTA	          5
#define COLOR_BROWN	              6
#define COLOR_DARKGRAY	          8
#define COLOR_LIGHTGRAY	          7
#define COLOR_LIGHTBLUE        	  9
#define COLOR_LIGHTGREEN          10
#define COLOR_CELESTE	          11
#define COLOR_LIGHTRED	          12
#define COLOR_ROSADO      	      13
#define COLOR_AMARILLO	          14
using namespace std;
int n,m;
int SolveCorrect(vector <int> Input1,int n)
{
    vector <int> Output;
    double tiempo=clock();
    //codigo correcto y lento

      int suma=0;
    for(int x=0; x<n; x++)suma+=Input1[x];

    //
    Output.push_back(suma);
    tiempo=clock()-tiempo;
    cout<<"SolveCorrect time: "<<tiempo<<" ";

    return Output;

}
int SolvePass(vector<int>Input1, int n)
{
    double tiempo=clock();
     vector <int> Output;
    //codigo que queremos probar

    int suma=0;
    for(int x=0; x<n; x++)suma+=Input1[x];


    //
    Output.push_back(suma);
    tiempo=clock()-tiempo;
    cout<<"SolvePass time: "<<tiempo<<endl;
    return suma;

}
void ContainNumbers(vector<int> *Input1,int n)
{
    for(int x =0; x<n; x++){Input1->push_back((rand()%MAXINPUT-MININPUT)+MININPUT);}
}
void ContainChars(vector<char> Input1,int n)
{
    for(int x =0; x<n; x++)Input1.push_back(char((rand()%MAXINPUT-MININPUT)+MININPUT));
}
void ContainStrings(vector<string> Input1,int n)
{
    int y;
    string cad;
    for(int x =0; x<n; x++)
    {
        y=(rand()%MAXINPUT-MININPUT)+MININPUT;
        cad="";
        for(int z=0; z<y; z++)cad+=(char((rand()%MAXINPUT-MININPUT)+MININPUT));
        Input1.push_back(cad);
    }
}
void CoutInputs(vector<int>Input,int n)
{
    vector<int>::iterator it;
    for(it=Input.begin(); it!=Input.end(); it++)cout<<*it<<" ";
    cout<<endl;
}
bool CompareSolutions(vector<int)
int main()
{
    int ResSolveCorrect;
    int ResSolvePass;
    while(1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_MAGENTA);
        n=((rand()%MAXN-MINN)+MINN);
        cout<<"Size N: "<<n<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        /*#Contenedores Ints#*/
        vector<int> Input1;
        //vector<int> Input2;

         /*#Contenedores float#*/
        //vector<float>Input1;
        //vector<float>Input2;

        /*#Contenedores chars#*/
        //vector<char>Input1;
        //vector<char>Input2;

        /*#Contenedores string#*/
        //vector<string>Input1;
        //vector<string>Input2;

        /*FUNCIONES*/
        ContainNumbers(&Input1,n);
        //ContainChar(Input1,n);

        /*COUTS DE VECTORES*/
        CoutInputs(Input1,n);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_CELESTE);
        ResSolveCorrect=SolveCorrect(Input1,n);
        ResSolvePass=SolvePass(Input1,n);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_AMARILLO);
        cout<<"Correct output: "<<ResSolveCorrect<<" Output :"<<ResSolvePass<<endl;
        if(ResSolveCorrect!=ResSolvePass)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_RED);
            cout<<"Wrong Answer"<<endl<<endl;
            break;
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR_LIGHTGREEN);
            cout<<"Accepted"<<endl<<endl;
        }
    }
}
