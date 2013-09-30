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

#define fi "10500.inp"
#define fo "10500.out"
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
char a[12][12],d[12][12],dd[12][12];
int nhang,ncot,move;
/**/
void xuly(int hang,char s[])
{
    int i;
    int l,c;
    l = strlen(s);
    c = 1;
    for(i=0;i<l;i++)
        if(s[i] == 'X')
        {
            a[hang][c] = s[i];
            d[hang][c] = '?';
            dd[hang][c] = 0;
            c++;
        }
        else if(s[i] == '0')
        {
            a[hang][c] = s[i];
            d[hang][c] = '?';
            dd[hang][c] = 0;
            c++;
        }
}
/**/
void output()
{
    int i,j;
    printf("\n");
    for(i=1;i<=ncot;i++)
        printf("|---");
    printf("|\n");
    for(i=1;i<=nhang;i++)
    {
        for(j=1;j<=ncot;j++)
            printf("| %c ",d[i][j]);
        printf("|\n");
        for(j=1;j<=ncot;j++)
            printf("|---");
        printf("|\n");
    }
    printf("\nNUMBER OF MOVEMENTS: %d\n",move);
}
/**/
void solve(int r,int c)
{
    int i;
    int px,py;
    bool go;
    move = 0;
    while(true)
    {
        go = false;
        d[r][c] = a[r][c];
        dd[r][c] = 1;
        for(i=0;i<4;i++)
        {
            px = r + h[i].x;
            py = c + h[i].y;
            if(px >= 1 && px <= nhang && py >= 1 && py <= ncot)
                d[px][py] = a[px][py];
        }
        for(i=0;i<4;i++)
        {
            px = r + h[i].x;
            py = c + h[i].y;
            if(px >= 1 && px <= nhang && py >= 1 && py <= ncot)
            {
                if(a[px][py] == '0' && dd[px][py] == 0)
                {
                    go = true;
                    move++;
                    break;
                }
            }
        }
        if(!go)
            break;
        r = px;
        c = py;
    }
    output();
}
/**/
void input()
{
    int i;
    int x,y;
    char temp[10000];
    while(true)
    {
        scanf("%d %d",&nhang,&ncot);
        if(!nhang && !ncot)
            break;
        scanf("%d %d",&x,&y);
        gets(temp);
        for(i=1;i<=nhang;i++)
        {
            gets(temp);
            xuly(i,temp);
        }
        solve(x,y);
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
