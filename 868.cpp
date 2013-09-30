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

#define fi "868.inp"
#define fo "868.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {0,-1,
                1,0,
                0,1,
                -1,0};
int a[110][110],d[110][110];
int nhang,ncot,row,col;
bool npath;
/**/
void dequy(int hang,int cot,int val,int maxval)
{
    int i;
    int x,y;
    if(hang == nhang && !val)
    {
        if(cot < col)
            col = cot;
        npath = true;
        return;    
    }
    
    for(i=0;i<4;i++)
    {
        x = hang + h[i].x;
        y = cot + h[i].y;
        if(x > 0 && x <= nhang && y > 0 && y <= ncot)
            if(a[x][y] == val + 1 && !d[x][y])
            {
                d[x][y] = 1;
                if(a[x][y] == maxval)
                    dequy(x,y,0,maxval+1);
                else
                    dequy(x,y,val+1,maxval);
                d[x][y] = 0;
            }
    }
}
/**/
void solve()
{
    int i;
    
    for(i=1;i<=ncot;i++)
        if(a[1][i] == 1)
        {
            col = ncot;
            npath = false;
            dequy(1,i,0,2);
            if(npath)
                break;
        }
    printf("%d %d\n%d %d\n",1,i,nhang,col);
}
/**/
void input()
{
    int i,j;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&nhang,&ncot);
        for(i=1;i<=nhang;i++)
            for(j=1;j<=ncot;j++)
            {
                scanf("%d",&a[i][j]);
                d[i][j] = 0;
            }
        solve();
        if(ntest)
            printf("\n");
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
