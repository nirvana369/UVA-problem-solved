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

#define fi "10977.inp"
#define fo "10977.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
toado q[41000];
long kc[41000];
int a[210][210],d[210][210];
int nhang,ncot;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=nhang;i++)
    {
        for(j=1;j<=ncot;j++)
        {
            a[i][j] = 0;
            d[i][j] = 0;
        }
    }
}
/**/
long solve(int hang,int cot)
{
    long dau,cuoi;
    toado p;
    long i;
    dau = -1;
    cuoi = 0;
    if(a[hang][cot] == 1)
        return -1;
    d[hang][cot] = 1;
    q[0].x = hang;
    q[0].y = cot;
    kc[0] = 0;

    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;            
            if(p.x >= 1 && p.x <= nhang && p.y >= 1 && p.y <= ncot)
                if(d[p.x][p.y] == 0 && a[p.x][p.y] == 0)
                {
                    cuoi++;
                    q[cuoi] = p;
                    kc[cuoi] = kc[dau] + 1;
                    d[p.x][p.y] = 1;
                    if(p.x == nhang && p.y == ncot)
                        return kc[cuoi];
                }
        }
    }
    return -1;
}
/**/
void markj(int x,int y,int eff)
{
    int i,j;
    int x1,x2,y1,y2;
    long temp,temp1;
    temp1 = eff * eff;
    x1 = x - eff; 
    x2 = x + eff;
    y1 = y - eff;
    y2 = y + eff;
    if(x1 < 1)
        x1 = 1;
    if(y1 < 1)
        y1 = 1;
    if(x2 > nhang)
        x2 = nhang;
    if(y2 > ncot)
        y2 = ncot;
    for(i=x1;i<=x2;i++)
        for(j=y1;j<=y2;j++)
        {
            temp = (i - x) * (i - x) + (j - y) * (j - y);
            if(temp <= temp1)
                a[i][j] = 1;
        }
}
/**/
void input()
{
    int i;
    int n;
    long kq;
    int x,y,loud;
    
    while(true)
    {
        scanf("%d %d",&nhang,&ncot);
        if(!nhang && !ncot)
            break;
        khoitao();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&x,&y,&loud);
            markj(x,y,loud);
        }
        kq = solve(1,1);
        if(kq == -1)
            printf("Impossible.\n");
        else
            printf("%ld\n",kq);
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
