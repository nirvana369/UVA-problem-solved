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

#define fi "11760.inp"
#define fo "11760.out"
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
int row[10010],col[10010];
int nhang,ncot,n;
/**/
void khoitao()
{
    int i;
    int maxx;
    maxx = nhang > ncot ? nhang : ncot;
    for(i=0;i<=maxx;i++)
        row[i] = col[i] = 0;
}
/**/
bool kiemtra(int x,int y)
{
    if(x >= 0 && x < nhang &&  y >= 0 && y < ncot && !row[x] && !col[y])
        return true;
    return false;
}
/**/
void input()
{
    int i;
    int hang,cot;
    int id;
    bool escape;
    id = 1;
    while(scanf("%d %d %d",&nhang,&ncot,&n))
    {
        if(!nhang && !ncot && !n)
            break; 
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&hang,&cot);
            row[hang] = 1;
            col[cot]  = 1;
        }
        scanf("%d %d",&hang,&cot);
        escape = kiemtra(hang,cot);
        if(!escape)
            for(i=0;i<4;i++)
            {
                escape = kiemtra(hang+h[i].x,cot+h[i].y);
                if(escape)
                    break;
            }
        if(escape) 
            printf("Case %d: Escaped again! More 2D grid problems!\n",id++);
        else
            printf("Case %d: Party time! Let's find a restaurant!\n",id++);
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
