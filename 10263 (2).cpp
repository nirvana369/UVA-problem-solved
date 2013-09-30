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
double dd(toado a,toado b)
{
    return a.x * b.x + a.y * b.y;
}
/**/
void solve(toado a,toado b)
{
    double tmp;
    toado am,ab;
    
    am.x = m.x - a.x;
    am.y = m.y - a.y;
    
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    t = dd(am,ab) / dd(ab,ab);
}
/**/
void input()
{
    while(scanf("%lf %lf %d",&xp.x,&xp.y,&n) == 3)
    {
        for(i=0;i<=n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        kq = 1000000000;
        for(i=0;i<n;i++)
            solve(p[i],p[i+1]);
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
