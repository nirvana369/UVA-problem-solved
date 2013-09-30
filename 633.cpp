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

#define fi "633.inp"
#define fo "633.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[13] = {-2,-1,
                -2,1,
                -1,2,
                1,2,
                2,-1,
                2,1,
                -1,-2,
                1,-2,
                -2,-2,
                2,2,
                -2,2,
                2,-2};
toado q[10000];
toado xp,kt;
int a[42][42][5],tt[10000],kc[10000];
int n,sobuoc;
/**/
int movek(int dau,int cuoi)
{
    int i;
    toado p;
    
    for(i=0;i<8;i++)
    {
        p.x = q[dau].x + h[i].x;
        p.y = q[dau].y + h[i].y;
        if(p.x > 0 && p.x <= n && p.y > 0 && p.y <= n)
        {
            if(a[p.x][p.y][1] == 0)
            {
                cuoi++;
                q[cuoi] = p;
                a[p.x][p.y][1] = 1;
                tt[cuoi] = 1;
                kc[cuoi] = kc[dau] + 1;
                if(p.x == kt.x && p.y == kt.y)
                {
                    sobuoc = kc[cuoi];
                    return -1;
                }
            }
        }
    }
    return cuoi;
}
/**/
int moveb(int dau,int cuoi)
{
    int i;
    toado p ;
    for(i=8;i<12;i++)
    {
        p.x = q[dau].x + h[i].x;
        p.y = q[dau].y + h[i].y;
        if(p.x > 0 && p.x <= n && p.y > 0 && p.y <= n)
        {
            if(a[p.x][p.y][2] == 0)
            {
                cuoi++;
                q[cuoi] = p;
                a[p.x][p.y][2] = 1;
                tt[cuoi] = 2;
                kc[cuoi] = kc[dau] + 1;
                if(p.x == kt.x && p.y == kt.y)
                {
                    sobuoc = kc[cuoi];
                    return -1;
                }
            }
        }
    }
    return cuoi;
}
/**/
int movet(int dau,int cuoi)
{
    toado p;
    if(q[dau].x - 1 > n - q[dau].x)
    {
        p.x = 1 + (n-q[dau].x);
        p.y = q[dau].y;
        if(a[p.x][p.y][3] == 0)
        {
            cuoi++;
            q[cuoi] = p;
            tt[cuoi] = 3;
            a[p.x][p.y][3] = 1;
            kc[cuoi] = kc[dau] + 1;
            if(p.x == kt.x && p.y == kt.y)
            {
                sobuoc = kc[cuoi];
                return -1;
            }
        }
    }
    else
    {
        p.x = n - (q[dau].x - 1);
        p.y = q[dau].y;
        if(a[p.x][p.y][3] == 0)
        {
            cuoi++;
            q[cuoi] = p;
            tt[cuoi] = 3;
            a[p.x][p.y][3] = 1;
            kc[cuoi] = kc[dau] + 1;
            if(p.x == kt.x && p.y == kt.y)
            {
                sobuoc = kc[cuoi];
                return -1;
            }
        }
    }
    
    if(q[dau].y - 1 > n - q[dau].y)
    {
        p.x = q[dau].x;
        p.y = 1 + (n-q[dau].y);
        if(a[p.x][p.y][3] == 0)
        {
            cuoi++;
            q[cuoi] = p;
            tt[cuoi] = 3;
            a[p.x][p.y][3] = 1;
            kc[cuoi] = kc[dau] + 1;
            if(p.x == kt.x && p.y == kt.y)
            {
                sobuoc = kc[cuoi];
                return -1;
            }
        }
    }
    else
    {
        p.x = q[dau].x;
        p.y = n - (q[dau].y - 1);
        if(a[p.x][p.y][3] == 0)
        {
            cuoi++;
            q[cuoi] = p;
            tt[cuoi] = 3;
            a[p.x][p.y][3] = 1;
            kc[cuoi] = kc[dau] + 1;
            if(p.x == kt.x && p.y == kt.y)
            {
                sobuoc = kc[cuoi];
                return -1;
            }
        }
    }
    return cuoi;
}
/**/
void loang()
{
    int dau,cuoi;
    int i;
    q[0] = xp;
    tt[0] = 0;
    for(i=1;i<4;i++)
        a[xp.x][xp.y][i] = 1;
    dau = -1;
    cuoi = 0;
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<4;i++)
            if(tt[dau] != i)
            {
                if(i == 1)
                    cuoi = movek(dau,cuoi);
                if(i == 2)
                    cuoi = moveb(dau,cuoi);
                if(i == 3)
                    cuoi = movet(dau,cuoi); 
                if(cuoi == -1)
                    return;
            }
    }
    sobuoc = -1;
}
/**/
void output()
{
    if(sobuoc < 0)
        printf("Solution doesn't exist\n");
    else
        printf("Result : %d\n",sobuoc);
}
/**/
void khoitao()
{
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<4;k++)
                a[i][j][k] = 0;
}
/**/
void input()
{
    int i;
    int x,y;
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        n *= 2;
        khoitao();
        scanf("%d %d",&xp.x,&xp.y);
        scanf("%d %d",&kt.x,&kt.y);
        while(scanf("%d %d",&x,&y) == 2)
        {
            if(!x && !y)
                break;
            for(i=1;i<4;i++)
                a[x][y][i] = 1;
        }
        sobuoc = 0;
        if(xp.x != kt.x || xp.y != kt.y)
            loang();
        output();
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
