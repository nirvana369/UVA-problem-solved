/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10047.inp"
#define fo "10047.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
struct mono{
                int x,y,m,dir;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
mono q[16000];
mono xp,kt;
int kc[16000],d[30][30][6][6];
char a[30][30];
int nhang,ncot;
/**/
void xuly(int id,char s[])
{
    int i,j,k;
    i = 0;
    while(s[i])
    {
        for(j=0;j<4;j++)
            for(k=0;k<5;k++)
                d[id][i][j][k] = 0;
            
        if(s[i] == 'S')
        {
            xp.x = id;
            xp.y = i;
            xp.m = 0;
            xp.dir = 0;
            a[id][i] = '.';
        }
        else if(s[i] == 'T')
        {
            kt.x = id;
            kt.y = i;
            kt.m = 0;
            kt.dir = 0;
            a[id][i] = '.';
        }
        i++;
    }
}
/**/
bool thesame()
{
    if(xp.x != kt.x || xp.y != kt.y || xp.m != kt.m)
        return false;
    return true;
}
/**/
int solve()
{
    int i;
    int dau,cuoi;
    int rot;
    
    dau = -1;
    cuoi = 0;
    kc[0] = 0;
    q[0] = xp;
    d[xp.x][xp.y][xp.dir][xp.m] = 1;
    while(dau != cuoi)
    {
        dau++;
            
        xp = q[dau];
        
        xp.dir = q[dau].dir+1;
        if(xp.dir == 4)
            xp.dir = 0;
        if(!d[xp.x][xp.y][xp.dir][xp.m])
        {
            d[xp.x][xp.y][xp.dir][xp.m] = 1;
            cuoi++;
            kc[cuoi] = kc[dau] + 1;
            q[cuoi] = xp;
        }
        ////////////
        xp.dir = q[dau].dir-1;
        if(xp.dir < 0)
            xp.dir = 3;
        if(!d[xp.x][xp.y][xp.dir][xp.m])
        {
            d[xp.x][xp.y][xp.dir][xp.m] = 1;
            cuoi++;
            kc[cuoi] = kc[dau] + 1;
            q[cuoi] = xp;
        }
       //////////////////////////    
        xp.x = q[dau].x + h[q[dau].dir].x;
        xp.y = q[dau].y + h[q[dau].dir].y;
        xp.m = q[dau].m+1;
        if(xp.m == 5)
            xp.m = 0;
        xp.dir = q[dau].dir;
        if(xp.x >= 0 && xp.x < nhang && xp.y >= 0 && xp.y < ncot)
            if(!d[xp.x][xp.y][xp.dir][xp.m] && a[xp.x][xp.y] == '.')
            {
                d[xp.x][xp.y][xp.dir][xp.m] = 1;
                cuoi++;
                kc[cuoi] = kc[dau] + 1;
                q[cuoi] = xp;
            }
            
        if(thesame())
            return kc[cuoi];
    }
    return -1;
}
/**/
void input()
{
    int i,id;
    int kq;
    id = 0;
    while(scanf("%d %d",&nhang,&ncot))
    {
        if(!nhang && !ncot)
            break;
        for(i=0;i<nhang;i++)
        {
            scanf("%s",&a[i]);
            xuly(i,a[i]);
        }
        kq = solve();
        if(id)
            printf("\n");
        printf("Case #%d\n",++id);
        if(kq != -1)
            printf("minimum time = %d sec\n",kq);
        else
            printf("destination not reachable\n");
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
