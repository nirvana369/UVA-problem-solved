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

#define fi "10610.inp"
#define fo "10610.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
toado p[1100];
int q[1100],d[1100],kc[1100];
double dist;
int n,v,t;
/**/
bool kiemtra(int i1,int i2)
{
    double val;
    val = sqrt((p[i1].x - p[i2].x) * (p[i1].x - p[i2].x) + (p[i1].y - p[i2].y) * (p[i1].y - p[i2].y));
    if(val > dist)
        return false;
    return true;
}
/**/
int solve()
{
    int dau,cuoi;
    int i;
    dau = -1;
    cuoi = 0;
    d[0] = 1;
    q[0] = 0;
    kc[dau] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<n;i++)
            if(!d[i] && kiemtra(q[dau],i))
            {
                cuoi++;
                q[cuoi] = i;
                kc[cuoi] = kc[dau] + 1;
                d[i] = 1;
                if(i == 1)
                    return kc[dau];
            }
    }
    return -1;
}
/**/
void input()
{
    char s[10000];
    int kq;
    while(scanf("%d %d",&v,&t) == 2)
    {
        if(!v && !t)
            break;
        dist = 60*v*t;
        n = 0;
        gets(s);
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            sscanf(s,"%lf %lf",&p[n].x,&p[n].y);
            d[n] = 0;
            n++;
        }
        kq = solve();
        if(kq != -1)
            printf("Yes, visiting %d other holes.\n",kq);
        else
            printf("No.\n");
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
