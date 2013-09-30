/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>
#include <vector>

#define fi "833.inp"
#define fo "833.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
            
struct duongthang{
                    toado dinh[2];
                };
duongthang line[1000];
int n,m;
toado xp;
/**/
int fall(toado p,toado q)
{
    int a1,b1,c1,a2,b2,c2,d,dx,dy,x,y;
    toado kt;
    kt.x = 0;
    kt.y = xp.y;
    
    a1 = p.y - q.y;
    b1 = q.x - p.x;
    c1 = -(a1 * p.x + b1 * p.y);
    
    a2 = xp.y - kt.y;
    b2 = kt.x - xp.x;
    c2 = -(a2 * xp.x + b2 * xp.y);
    
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = c1 * a2 - c2 * a1;
    
    if(d != 0)
    {
        x = dx/d;
        y = dy/d;
        if((x - p.x) * (x-q.x) > 0 || (y - p.y) * (y-q.y) > 0)
            return xp.x + 10;
        return x;    
    }
    
    return xp.x + 10;
}
/**/
bool diff(toado q,toado p)
{
    if(p.x != q.x || p.y != q.y)
        return true;
    return false;
}
/**/
void solve()
{
    int i;
    int temp,tg;
    int vt;
    while(xp.x != 0)
    {
        temp = 0;
        vt = -1;
        for(i=0;i<n;i++)
        {
            tg = fall(line[i].dinh[0],line[i].dinh[1]);
            if(tg > temp && tg <= xp.x)
            {
                if(diff(xp,line[i].dinh[1]))
                {
                    temp = tg;
                    vt = i;
                }
            }
        }
        if(vt == -1) 
            xp.x = 0;
        else
            xp = line[vt].dinh[1];
    }
    printf("%d\n",xp.y);
}
/**/
void input()
{
    int i,j;
    int ntest;
    toado tg;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<2;j++)
                scanf("%d %d",&line[i].dinh[j].y,&line[i].dinh[j].x);
            if(line[i].dinh[0].x < line[i].dinh[1].x)
            {
                tg = line[i].dinh[0];
                line[i].dinh[0] = line[i].dinh[1];
                line[i].dinh[1] = tg;
            }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&xp.y,&xp.x);
            solve();
        }
        if(ntest)
            printf("\n");
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
