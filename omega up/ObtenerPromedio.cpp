#include<stdio.h>
#include <iomanip>

int main()
{
    int n; 
    scanf("%d",&n);
    float m;
    float promedio=0.0;
    for(int x =0; x<n; x++)
    {
        scanf("%f",&m);
        promedio+=m;
    }
    promedio/=n;
    printf("%0.2f",promedio);
    
}