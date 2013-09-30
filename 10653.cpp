/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10653.inp"
#define fo "10653.out"
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
                
int d[1001][1001];
toado q[1000100];
long kc[1000100];
int nr,nc;
toado s,l;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<nr;i++)
        for(j=0;j<nc;j++)
            d[i][j] = 0;
}
/**/
void loang()
{
    int i;
    long dau,cuoi;
    toado p;
    
    dau = -1;
    cuoi = 0;
    q[0] = s;
    d[s.x][s.y] = 1;
    kc[0] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.y >=0 && p.x < nr && p.y < nc)
                if(d[p.x][p.y] == 0)
                {
                    cuoi++;
                    kc[cuoi] = kc[dau] + 1;
                    q[cuoi] = p;
                    d[p.x][p.y] = 1;
                    if(p.x == l.x && p.y == l.y)
                    {
                        printf("%ld\n",kc[cuoi]);   
                        return;
                    }
                }
        }
    }
    printf("0\n");
    return;
}
/**/
void input()
{
    int i,j;
    int nbomb,mr;
    int r,c;
    
    while(true)
    {
        scanf("%d %d",&nr,&nc);
        if(!nr && !nc)
            break;
        khoitao();
        scanf("%d",&mr);
        for(i=0;i<mr;i++)
        {
            scanf("%d %d",&r,&nbomb);
            for(j=0;j<nbomb;j++)
            {
                scanf("%d",&c);
                d[r][c] = 2;
            }
        }
        scanf("%d %d %d %d",&s.x,&s.y,&l.x,&l.y);
        loang();
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
