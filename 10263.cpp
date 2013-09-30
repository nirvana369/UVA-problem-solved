/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10263.inp"
#define fo "10263.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
/**/
double kc(toado a,toado b) 
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
/**/
int nt(double a, double b, double c) {
    return (a >= b && a <= c) || (a <= b && a >= c);
}
/**/
void input()
{
    double tmp;
    double minkc,ax,ay;
    double a,b,c,t;
    toado p[110];
    toado pos,m;
    int n;
    
    while(scanf("%lf %lf",&m.x,&m.y) == 2) 
    {
        scanf("%d",&n);
        int i;
        for(i=0;i<=n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        
        minkc = kc(m,p[0]);
        ax = p[0].x;
        ay = p[0].y;
        for(i=0;i<n;i++) {
            a = p[i].y-p[i+1].y;
            b = p[i+1].x - p[i].x;
            c = -(a*p[i].x + b*p[i].y);
            
            t = (-a*m.x-b*m.y-c) / (a*a+b*b);
            pos.x = m.x + t * a; 
            pos.y = m.y + t * b;
            if(nt(pos.x, p[i].x, p[i+1].x) && nt(pos.y, p[i].y, p[i+1].y)) 
            {
                tmp = fabs(a*m.x+b*m.y+c)/sqrt(a*a+b*b);
                if(minkc > tmp)
                {
                    minkc = tmp;
                    ax = pos.x;
                    ay = pos.y;
                }
            }
            
            tmp = kc(m,p[i+1]);
            
            if(minkc > tmp)
            {
                minkc = tmp;
                ax = p[i+1].x;
                ay = p[i+1].y;
            }
        }
        printf("%.4lf\n%.4lf\n",ax,ay);
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
