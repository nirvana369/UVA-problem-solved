/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10913.inp"
#define fo "10913.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = { -1,0,
                1,0,
                0,-1,
                0,1};
int a[80][80],gt[80][80];
int n,s,t,kq;
/**/
void dq(int row,int col,long long val,int tg)
{
    int i;
    int r,c;
    int tmp;
    
    if(row == (n-1) && col == (n-1))
    {
        if(val >= s && tg < kq)
            kq = tg;
        return;
    }
    
    for(i=0;i<4;i++)    
    {
        r = row + h[i].x;
        c = col + h[i].y;
        if(r >= 0 && c >= 0 && r < n && c < n)
            if(val + a[r][c] > gt[r][c])
            {
                gt[r][c] = val + a[r][c];
                tmp = a[r][c];
                a[r][c] = 0;
                
                dq(r,c,gt[r][c],tg+1);
                
                a[r][c] = tmp;
            }
    }
}
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            a[i][j] = 0;
            gt[i][j] = -1;
        }
}
/**/
void input()
{
    int i,j;
    int id,tmp;
    int x,y;
    
    id = 1;
    while(scanf("%d %d %d",&n,&t,&s))
    {
        if(!n && !s && !t)
            break;
        khoitao();
        for(i=0;i<t;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
        }

        kq = n*n+1;

        dq(0,0,a[0][0],0);
        printf("Case %d: %d\n",id++,kq);
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
