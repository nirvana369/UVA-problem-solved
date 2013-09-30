/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "379.inp"
#define fo "379.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {1,0,
                0,1,
                0,-1,
                -1,0};
                
toado p[100];
int a[8][8];
int k;
/**/
void _init()
{
    int i,j;
    k = 1;
    for(i=0;i<7;i++)
        for(j=0;j<7;j++)
        {
            if(i == 0 || i == 1 || i == 5 || i == 6)
            {
                if(j > 1 && j < 5)
                {
                    p[k].x = i;
                    p[k].y = j;
                    k++;
                    a[i][j] = 0;
                }
                else
                    a[i][j] = -1;
            }
            else
            {
                p[k].x = i;
                p[k].y = j;
                k++;
                a[i][j] = 0;
            }
        }
}
/**/
void solve()
{
    int tong;
    int i,j,dir;
    toado pos;
    
    for(i=k-1;i>0;i--)
    {
        if(!a[p[i].x][p[i].y])
        {
            for(dir=0;dir<4;dir++)
            {
                pos = p[i];
                for(j=0;j<2;j++)
                {
                    pos.x += h[dir].x;
                    pos.y += h[dir].y;
                    if(pos.x >= 0 && pos.x < 7 && pos.y >= 0 && pos.y < 7)
                    {
                        if(a[pos.x][pos.y] == -1 || !a[pos.x][pos.y])
                            break;
                    }
                    else
                        break;
                }
                
                if(j == 2)
                {
                    a[p[i].x][p[i].y] = 1;
                    pos = p[i];
                    for(j=0;j<2;j++)
                    {
                        pos.x += h[dir].x;
                        pos.y += h[dir].y;
                        a[pos.x][pos.y] = 0;
                    }    
                    i = k;
                    break;
                }
            }
        }   
    }
    
    tong = 0;
    for(i=k-1;i>0;i--)
    {
        if(a[p[i].x][p[i].y])
            tong += i;
    }
    printf("%d\n",tong);
}
/**/
void khoitao()
{
    int i;
    
    for(i=k-1;i>0;i--)
        a[p[i].x][p[i].y] = 0;
}
/**/
void input()
{
    int ntest;
    int vt;
    
    scanf("%d",&ntest);
    printf("HI Q OUTPUT\n");
    _init();
    while(ntest--)
    {
        while(true)
        {
            scanf("%d",&vt);
            if(!vt)
                break;
            a[p[vt].x][p[vt].y] = 1;
        }
        solve();
        if(ntest)
            khoitao();
    }
    printf("END OF OUTPUT\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
