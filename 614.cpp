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

#define fi "614.inp"
#define fo "614.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {0,-1,
                -1,0,
                0,1,
                1,0};
toado xp,kt;
int a[15][15],vt[15][15],d[110][110],dq[15][15];
int nhang,ncot;
bool reach;
/**/
void danhdau(int row,int col,int dau,int cuoi)
{
    int i;
    for(i=dau;i<=cuoi;i++)
        d[vt[row][col]][vt[row+h[i].x][col+h[i].y]] = d[vt[row+h[i].x][col+h[i].y]][vt[row][col]] = 0;
}
/**/
void khoitao()
{
    int i,j,id;
    for(i=0;i<nhang*ncot;i++)
        for(j=0;j<nhang*ncot;j++)
            d[i][j] = 1;
    id = 0;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
        {
            vt[i][j] = id++;
            a[i][j] = dq[i][j] = 0;
        }
    xp.x--;
    xp.y--;
    kt.x--;
    kt.y--;
    reach = false;
}
/**/
void solve(int id,int row,int col)
{
    int i;
    if(row == kt.x && col == kt.y)
    {
        a[row][col] = id;
        reach = true;
        return;
    }
    for(i=0;i<4;i++)
        if(col+h[i].y >= 0 && row+h[i].x >= 0 && col+h[i].y < ncot && row+h[i].x < nhang)
        if(d[vt[row][col]][vt[row+h[i].x][col+h[i].y]] && !dq[row+h[i].x][col+h[i].y])
        {
            a[row][col] = id;
            dq[row][col] = 1;
            solve(id+1,row+h[i].x,col+h[i].y);
            if(reach)
                return;
            dq[row][col] = 0;
        }
    a[row][col] = -1;
}
/**/
void output()
{
    int i,j;
    for(j=0;j<ncot;j++)
        printf("+---");
    printf("+\n");
    for(i=0;i<nhang;i++)
    {
        if(i)
        {
            for(j=0;j<ncot;j++)
            {
                printf("+");
                if(!d[vt[i][j]][vt[i+h[1].x][j+h[1].y]])
                    printf("---");
                else
                    printf("   ");
            }
            printf("+\n");
        }
        printf("|");
        for(j=0;j<ncot;j++)
        {
            if(j)
            {
                if(!d[vt[i][j]][vt[i+h[0].x][j+h[0].y]])
                    printf("|");
                else
                    printf(" ");
            }       
            if(a[i][j] > 0)
                printf("%3d",a[i][j]);
            else if(a[i][j] < 0)
                printf("???");
            else
                printf("   ");
        }
        printf("|\n");
    }
    for(j=0;j<ncot;j++)
        printf("+---");
    printf("+\n\n\n");
}
/**/
void input()
{
    int i,j;
    int temp,id;
    id = 1;
    while(scanf("%d %d %d %d %d %d",&nhang,&ncot,&xp.x,&xp.y,&kt.x,&kt.y))
    {
        if(!nhang && !ncot)
            break;
        khoitao();
        for(i=0;i<nhang;i++)
            for(j=0;j<ncot;j++)
            {
                scanf("%d",&temp);
                if(temp == 1)
                    danhdau(i,j,2,2);
                if(temp == 2)
                    danhdau(i,j,3,3);
                if(temp == 3)
                    danhdau(i,j,2,3);
            }
        solve(1,xp.x,xp.y);
        printf("Maze %d\n\n",id++);
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
