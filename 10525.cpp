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

#define fi "10525.inp"
#define fo "10525.out"
#define maxi 32767
/**/
using namespace std;
/**/
struct data{
                int d,t,dist;
            };
data a[110][110];
int d[110],khoangcach[110],thoigian[110];
int n,nroad;
/**/
int timnhan()
{
    int i;
    int vt,val;
    val = maxi;
    vt = -1;
    for(i=1;i<=n;i++)
        if(!d[i] && val > thoigian[i])
        {
            val = thoigian[i];
            vt = i;
        }
    return vt;
}
/**/
void gannhan(int xp)
{
    int i;
    for(i=1;i<=n;i++)
        if(a[xp][i].d)
            if(thoigian[xp] + a[xp][i].t <= thoigian[i])
            {
               if(thoigian[xp] + a[xp][i].t == thoigian[i]) 
               {
                    if(khoangcach[xp] + a[xp][i].dist < khoangcach[i])
                    {
                        thoigian[i] =  thoigian[xp] + a[xp][i].t;
                        khoangcach[i] = khoangcach[xp] + a[xp][i].dist;
                    }
                }
                else
                {
                    thoigian[i] =  thoigian[xp] + a[xp][i].t;
                    khoangcach[i] = khoangcach[xp] + a[xp][i].dist;                    
                }
            }
}
/**/
void _init()
{
    int i;
    for(i=1;i<=n;i++)
    {
        d[i] = 0;
        thoigian[i] = maxi;
        khoangcach[i] = maxi;
    }
}
/**/
void solve(int dau,int cuoi)
{
    int io;
    
    _init();
    thoigian[dau] = 0;
    khoangcach[dau] = 0;
    do
    {
        io = timnhan();
        if(io == -1)
            break;
        d[io] = 1;
        if(io != cuoi)
            gannhan(io);
    }while(true);
    
    if(thoigian[cuoi] != maxi)
        printf("Distance and time to reach destination is %d & %d.\n",khoangcach[cuoi],thoigian[cuoi]);
    else
        printf("No Path.\n");
}   
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            a[i][j].d = a[j][i].d = 0;
            a[i][j].t = a[j][i].t = 0;
            a[i][j].dist = a[j][i].dist = 0;
        }
        a[i][i].d = 0;
    }
}
/**/
void input()
{
    int i;
    int x,y,tg,kc,q;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&nroad);
        khoitao();
        for(i=0;i<nroad;i++)
        {
            scanf("%d %d %d %d",&x,&y,&tg,&kc);
            if(a[x][y].d)
            {
                if(tg < a[x][y].t)
                {
                    a[x][y].t = a[y][x].t = tg;
                    a[x][y].dist = a[y][x].dist = kc;
                }
                else if(tg == a[x][y].t)
                    if(kc < a[x][y].dist)
                    {
                        a[x][y].t = a[y][x].t = tg;
                        a[x][y].dist = a[y][x].dist = kc;
                    }
            }
            else
            {
                a[x][y].d = a[y][x].d = 1;
                a[x][y].t = a[y][x].t = tg;
                a[x][y].dist = a[y][x].dist = kc;
            }
        }
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&x,&y);
            solve(x,y);
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
