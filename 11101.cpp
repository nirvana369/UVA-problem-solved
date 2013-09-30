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

#define fi "11101.inp"
#define fo "11101.out"
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

int d[2005][2005];
toado q[4000010];
long kc[4000010];
long dau,cuoi;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<2001;i++)
    {
        for(j=i+1;j<2001;j++)
            d[i][j] = d[j][i] = 0;
        d[i][i] = 0;
    }
}
/**/
long loang()
{
    int i;
    toado p;
    
    dau = -1;
    cuoi--;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p = q[dau];
            p.x += h[i].x;
            p.y += h[i].y;
            if(p.x >= 0 && p.x < 2001 && p.y >= 0 && p.y < 2001)
                if(d[p.x][p.y] != 1)
                {
                    cuoi++;
                    q[cuoi] = p;
                    kc[cuoi] = kc[dau] + 1;
                    
                    if(d[p.x][p.y] == 2)
                        return kc[cuoi];
                    
                    d[p.x][p.y] = 1;
                }
        }
    }
    return -1;
}
/**/
void input()
{
    int i;
    int m;
    while(scanf("%d",&cuoi))
    {
        if(!cuoi)
            break;
        khoitao();
        for(i=0;i<cuoi;i++)
        {
            kc[i] = 0;
            scanf("%d %d",&q[i].x,&q[i].y);
            d[q[i].x][q[i].y] = 1;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&q[cuoi].x,&q[cuoi].y);
            d[q[cuoi].x][q[cuoi].y] = 2;
        }
        printf("%ld\n",loang());
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
