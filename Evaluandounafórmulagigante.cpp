#include <stdio.h>

int main()
{
    float x,y,z;
    scanf("%f %f %f",&x,&y,&z);
   float a=(2*x+y)/z;
   float b= y*y*y-z;
   float c=x+2*y+3*z;
   float d=z-2*y-3*x;
   float e=x*x+z*z;
   float res=(a*b)/((c/d)+e);
   printf("%6f",res);
}
