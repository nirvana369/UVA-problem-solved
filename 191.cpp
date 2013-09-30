/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "191.inp"
#define fo "191.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
toado dau,cuoi,goc1,goc2;
double a1,b1,c1;
/**/
bool its(double xa,double ya,double xb,double yb)
{
    double a2,b2,c2,d,dx,dy;
    
    a2 = ya - yb;
    b2 = xb - xa;
    c2 = -(a2 * xa + b2 * ya);
    
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = c1 * a2 - c2 * a1;
    
    dx /= d;
    dy /= d;
    
    if((a2 * dx + b2 * dy + c2) != 0)
        return false;
    if((dx - xa) * (dx - xb) > 1e-7 || (dy - ya) * (dy - yb) > 1e-7)
        return false;
        
    if((dx - dau.x) * (dx - cuoi.x) > 1e-7 || (dy - dau.y) * (dy - cuoi.y) > 1e-7)
        return false;
    return true;
}
/**/
bool solve()
{
    a1 = dau.y - cuoi.y;
    b1 = cuoi.x - dau.x;
    c1 = -(a1 * dau.x + b1 * dau.y);
    
    if(its(goc1.x,goc1.y,goc2.x,goc1.y))
        return true;
    if(its(goc1.x,goc1.y,goc1.x,goc2.y))
        return true;
    if(its(goc1.x,goc2.y,goc2.x,goc2.y))
        return true;
    if(its(goc2.x,goc1.y,goc2.x,goc2.y))
        return true;
    if(dau.x >= goc1.x && dau.x <= goc2.x && cuoi.x >= goc1.x && cuoi.x <= goc2.x)
        if(dau.y >= goc2.y && dau.y <= goc1.y && cuoi.y >= goc2.y && cuoi.y <= goc1.y)
            return true;
    return false;
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&dau.x,&dau.y,&cuoi.x,&cuoi.y,&goc1.x,&goc1.y,&goc2.x,&goc2.y);
        if(goc1.x > goc2.x)
            swap(goc1.x, goc2.x);
        if(goc1.y < goc2.y)
            swap(goc1.y, goc2.y);
        if(solve())
            printf("T\n");
        else
            printf("F\n");
    }
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
