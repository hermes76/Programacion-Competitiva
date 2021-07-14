#include <iostream>
using namespace std;
bool comp(int a, int b, int c)
{
    return (a<=b and b<c);
}
int Area(int x1,int x2,int x3, int x4,int y1,int y2,int y3, int y4)
{
    int area=0;
    if(comp(x1,x3,x2))
    {
        if(comp(y1,y3,y2))area=(abs(min(x4,x2)-x3))*(abs(min(y4,y2)-y3));
        else if(comp(y1,y4,y2))area=(abs(min(x4,x2)-x3))*(abs(max(y3,y1)-y3));
    }else if (comp(x1,x4,x2))
    {
        if(comp(y1,y3,y2))area=(abs(max(x3,x1)-x4))*(abs(min(y4,y2)-y3));
        else if(comp(y1,y4,y2))area=(abs(max(x3,x1)-x4))*(abs(max(y3,y1)-y3));
    }
    return area;
}
int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int area=Area(x1,x2,x3,x4,y1,y2,y3,y4);
    int area1,area2;
    if(area==0)
        area=Area(x3,x4,x1,x2,y3,y4,y1,y2);
    area1=abs(x1-x2)*abs(y1-y2);
    area2=abs(x3-x4)*abs(y3-y4);
    cout<<area1+area2-area;

}
