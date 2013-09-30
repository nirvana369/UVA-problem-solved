/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "143.inp"
#define fo "143.out"
/**/
using namespace std;
/**/
struct dt{
            double a,b,c;
         };
struct toado{
                double x,y;
            };
toado m;
dt line[3];
dt linep;
double x[3],y[3];
/**/
void make_line(double px,double py,double qx,double qy,dt &pt)
{
    pt.a = py - qy;
    pt.b = qx - px;
    pt.c = -(pt.a * px + pt.b * py);
}
/**/
bool cutline(dt p1,dt p2)
{
    double d,dx,dy;
    
    d = p1.a * p2.b - p1.b * p2.a;
    dx = p1.b * p2.c - p2.b * p1.c;
    dy = p1.c * p2.a - p2.c * p1.a;
    
    m.x = dx / d;
    m.y = dy / d;
    
    if(m.x * p1.a + m.y * p1.b + p1.c > 1e-7)
        return false;
    return true;
}
/**/
bool chk_in(double px,double py,double qx,double qy)
{
    if((m.x - px) * (m.x - qx) <= 1e-7 && (m.y - py) * (m.y - qy) <= 1e-7)
        return true;
    return false;
}
/**/
int chk()
{
    int i,j;
    int id1,id2;
    double minx,maxx;
    int tmp;
        
    minx = 1000;
    maxx = 0;
    
    for(i=0,j=0;i<3;i++)
    {
        if(!i)
        {
            id1 = 0;
            id2 = 1;
        }
        else if(i == 1)
        {
            id1 = 1;
            id2 = 2;
        }
        else
        {
            id1 = 0;
            id2 = 2;
        }
        
        if(cutline(line[i],linep))
            if(chk_in(x[id1],y[id1],x[id2],y[id2]))
            {
                minx = min(m.y,minx);
                maxx = max(m.y,maxx);
            }
    }
            
    if(minx - (int)minx < 1e-7)
        minx = (int)minx - 1;
    else
        minx = (int)minx;
    
    if((int)(maxx + 1) - maxx < 1e-7)
        maxx = (int)maxx+1;
    else
        maxx = (int)maxx;
    
    tmp =   (int)(maxx - minx);
    if(tmp < 0)
        tmp = 0;
    return tmp;
}
/**/
void solve()
{
    int i;
    double minx,maxx,miny,maxy;
    int dem;
    toado p1,p2;
    
    minx = min(x[0],min(x[1],x[2]));
    maxx = max(x[0],max(x[1],x[2]));
    
    miny = min(y[0],min(y[1],y[2]));
    maxy = max(y[0],max(y[1],y[2]));
    // lap pt duong thang
    make_line(x[0],y[0],x[1],y[1],line[0]);
    make_line(x[1],y[1],x[2],y[2],line[1]);
    make_line(x[0],y[0],x[2],y[2],line[2]);
    
    if(minx - (int)minx < 1e-7)
        minx = minx;
    else
        minx = (int)minx + 1;
        
    if((int)(maxx + 1) - maxx < 1e-7)
        maxx = (int)maxx + 1;
    else
        maxx = (int)maxx;
    
    dem = 0;
    
    for(i=(int)minx;i<=(int)maxx;i++)
    {
        p1.x = p2.x = i;
        p1.y = miny-1;
        p2.y = maxy+1;
        make_line(p1.x,p1.y,p2.x,p2.y,linep);
        dem += chk(); // kiem tra nam trong diem
    }
    printf("%4d\n",dem);
}
/**/
void input()
{
    int i;
    int dem;
    
    while(true)
    {
        dem = 0;
        for(i=0;i<3;i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
            if(x[i] == 0 && y[i] == 0)
                dem++;
        }
        if(dem == 3)
            break;
        solve();
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

