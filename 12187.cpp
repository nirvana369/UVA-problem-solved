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

#define fi "12187.inp"
#define fo "12187.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4]={-1,0,
             0,1,
             1,0,
             0,-1};
             
int n,nhang,ncot,k;
int a[105][105],d[105][105],m[105][105];
/**/
void war(int hang,int cot)
{
    int i;
    int lvl,px,py;
    
    for(i=0;i<4;i++)
    {
        px = hang + h[i].x;
        py = cot + h[i].y;
        if(px >= 0 && px < nhang && py >= 0 && py < ncot && m[px][py] == 0)
        {
            lvl = a[px][py];
            if(lvl == 0)
                lvl = n;
            if(a[hang][cot] + 1 == lvl)
            {
                d[px][py] = a[hang][cot];
                m[px][py] = 1;
            }
            else
                d[px][py] = a[px][py];
        }
    }
}
/**/
void solve()
{
    int i,ir,ic;
    for(i=0;i<k;i++)
    {
        for(ir=0;ir<nhang;ir++)
            for(ic=0;ic<ncot;ic++)
            {
                if(m[ir][ic] == 0)
                    d[ir][ic] = a[ir][ic];
                war(ir,ic);
            }
        for(ir=0;ir<nhang;ir++)
            for(ic=0;ic<ncot;ic++)
            {
                a[ir][ic] = d[ir][ic];
                m[ir][ic] = 0;
            }
    }
    for(ir=0;ir<nhang;ir++)
    {
        for(ic=0;ic<ncot;ic++)
        {
            if(ic)
                printf(" ");
            printf("%d",a[ir][ic]);
        }
        printf("\n");
    }
}
/**/
void input()
{
    int i,j;
    while(true)
    {
        scanf("%d %d %d %d",&n,&nhang,&ncot,&k);
        if(!n && !nhang && !ncot && !k)
            break;
        for(i=0;i<nhang;i++)
            for(j=0;j<ncot;j++)
            {
                scanf("%d",&a[i][j]);
                m[i][j] = 0;
            }
        solve();
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
