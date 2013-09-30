/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "949.inp"
#define fo "949.out"
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
toado q[10110];
bool d[110][110],g[105][105][105][105];
int t[110][110],kc[10010];
int nhang,ncot,n;
/**/
void khoitao()
{
    int i,j,k;
    int x,y;
        
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
        {
            d[i][j] = true;
            t[i][j] = 0;
            for(k=0;k<4;k++)
            {
                x = i + h[k].x;
                y = j + h[k].y;
                if(x >= 0 && y >= 0 && x < nhang && y < ncot)
                    g[i][j][x][y] = g[x][y][i][j] = true;
            }
        }
}
/**/
int loang()
{
    int i;
    int dau,cuoi;
    int x,y;
    
    dau = -1;
    cuoi = 0;
    q[0].x = 0;
    q[0].y = 0;
    d[0][0] = false;
    kc[0] = 0;
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            x = q[dau].x + h[i].x;
            y = q[dau].y + h[i].y;
            if(x >= 0 && y >= 0 && x < nhang && y < ncot)
                if(d[x][y] && g[q[dau].x][q[dau].y][x][y])
                {
                    cuoi++;
                    
                    if(kc[dau] + 1 > t[x][y])
                    {
                        q[cuoi].x = x;
                        q[cuoi].y = y;
                    }
                    else
                        q[cuoi] = q[dau];
                        
                    kc[cuoi] = kc[dau] + 1;
                    d[q[cuoi].x][q[cuoi].y] = false;
                    
                    if(q[cuoi].x == nhang-1 && q[cuoi].y == ncot-1)
                        return kc[cuoi];
                }
        }
    }
    return 0;
}
/**/
void input()
{
    int i;
    int m,x,y,x1,y1;
    int kq,tg;
    
    while(scanf("%d %d",&ncot,&nhang) == 2)
    {
        khoitao();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&y,&x,&y1,&x1);            
            g[x][y][x1][y1] = false;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&tg,&y,&x);
            t[x][y] = tg;
        }
        kq = loang();
        printf("%d\n",kq);
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
