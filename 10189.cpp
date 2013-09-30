/*
                                                        Hoang Linh 
                                                        
                                                        
                                            Problem: MINESWEEPER - 10189 (10189.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10189.inp"
#define fo "10189.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
int d[110][110];
char a[110][110];
int nhang,ncot;
/**/
void mines(int hang,int cot)
{
    int i;
    int px,py;
    for(i=0;i<8;i++)
    {
        px = hang + h[i].x;
        py = cot + h[i].y;
        if(px >= 0 && px < nhang && py >= 0 && py < ncot)
            d[px][py]++;
    }
}
/**/
void solve()
{
    int i,j;
    
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(a[i][j] == '*')
                mines(i,j);
                
    for(i=0;i<nhang;i++)
    {
        for(j=0;j<ncot;j++)
            if(a[i][j] == '*')
                printf("*");
            else
                printf("%d",d[i][j]);
        printf("\n");
    }
}
/**/
void input()
{
    int i,j;
    int id;
    id = 1;
    while(true)
    {
        scanf("%d %d",&nhang,&ncot);
        if(!nhang && !ncot)
            break;
        gets(a[0]);
        for(i=0;i<nhang;i++)
        {
            gets(a[i]);
            for(j=0;j<ncot;j++)
                d[i][j] = 0;
        }
        if(id != 1)
            printf("\n");
        printf("Field #%d:\n",id);
        solve();
        id++;
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
