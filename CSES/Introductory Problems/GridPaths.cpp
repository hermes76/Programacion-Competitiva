#include <iostream>
#define i int
#define R return;
#define b break;
std::string C;
char c;
i AX;
i AY;
i Ax[4]={1,0,-1,0};
i Ay[4]={0,1,0,-1};
bool V[9][9];
i G=0;
i DX;
i DY;
void A(i X, i Y,i P){
    if(X==1 && Y ==7 && P <48) R
    if(P==48)
    { 
        G++; 
        R
    }
    c=C[P];
    P++;
    V[Y][X]=1;
    if(c=='?')
    {
        DX=0;
        DY=0;
        if(V[Y][X+1]) DX++;
        if(V[Y][X-1]) DX++;
        if(V[Y+1][X] ) DY++;
        if(V[Y-1][X]) DY++;
        if((DX==2 && DY==0) || (DX==0 && DY==2)){V[Y][X]=0; R}
        for(i x=0; x<4; x++)
        { 
            AX=X+Ax[x]; 
            AY=Y+Ay[x]; 
            if(!V[AY][AX]) A(AX,AY,P);
        }
    }else{
        switch(c)
        {
        case 'L':
        if(!V[Y][X-1]) A(X-1,Y,P);
        b
        case 'R':
        if(!V[Y][X+1]) A(X+1,Y,P);
        b
        case 'U':
        if(!V[Y-1][X]) A(X,Y-1,P);
        b
        case 'D':
        if(!V[Y+1][X])A(X,Y+1,P);
        }
    }
    V[Y][X]=0;  
}
i main()
{
    std::cin>>C;
    for(i x=0; x<9; x++)
    {
        V[8][x]=1;
        V[x][8]=1;
        V[0][x]=1;
        V[x][0]=1;
    }
    A(1,1,0);
    std::cout<<G;
}