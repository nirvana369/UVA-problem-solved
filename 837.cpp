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

#define fi "837.inp"
#define fo "837.out"
/**/
using namespace std;
/**/
struct toado{
                double x1,x2,y1,y2;
                double a,b,c,light;
            };
toado line[1000];
double p[1000];
double h;
int dp,n;
/**/
void sapxep()
{
    int i,j;
    double temp;
    
    for(i=0;i<dp-1;i++)
        for(j=i+1;j<dp;j++)
            if(p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}
/**/
void solve()
{
    int i,j;
    int id;
    double mid,hs,a1,b1,c1,d,dx,dy;
    
    sapxep();
    
    id = dp + 1;
    printf("%d\n",id);
    printf("-inf %0.3lf %0.3lf\n",p[0],1.0);
    for(i=0;i<dp-1;i++)
    {
        mid = (p[i] + p[i+1]) / 2;
        a1 = h;
        b1 = 0;
        c1 = -(a1*mid);
        hs = 1.0;
        
        for(j=0;j<n;j++)
        {
            d = a1* line[j].b - line[j].a * b1;
            dx = b1 * line[j].c - c1 * line[j].b;
            dy = c1 * line[j].a - line[j].c *  a1;
            if(d != 0)
            {
                dx /= d;
                dy /= d;
                if(!((dx - line[j].x1) * (dx-line[j].x2) > 0 || (dy - line[j].y1) * (dy-line[j].y2) > 0))
                    hs *= line[j].light;
            }
        }
        printf("%0.3lf %0.3lf %0.3lf\n",p[i],p[i+1],hs);
    }
    printf("%0.3lf +inf %0.3lf\n",p[dp-1],1.0);
}
/**/
void input()
{
    int i,j;
    int ntest;
    bool u1,u2;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        dp = 0;
        h = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf %lf",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2,&line[i].light);
            line[i].a = line[i].y1 - line[i].y2;
            line[i].b = line[i].x2 - line[i].x1;
            line[i].c = -(line[i].a * line[i].x1 + line[i].b * line[i].y1);
            u1 = u2 = true;
            for(j=0;j<dp;j++)
            {
                if(line[i].x1 == p[j])
                    u1 = false;
                if(line[i].x2 == p[j])
                    u2 = false;
            }
            if(u1)
                p[dp++] = line[i].x1;
    
            if(u2 && line[i].x1 != line[i].x2)
                p[dp++] = line[i].x2;
    
            if(line[i].y1 > h)
                h = line[i].y1;
            if(line[i].y2 > h)
                h = line[i].y2;
        }
        solve();
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
