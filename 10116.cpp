/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10116.inp"
#define fo "10116.out"
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
                
int d[1000][1000];
char a[1000][1000];
int nhang,ncot,start;
/**/
int getdir(char kt)
{
    if(kt == 'N')
        return 0;
    if(kt == 'W')
        return 3;
    if(kt == 'S')
        return 2;
    return 1;
}
/**/
void solve()
{
    int x,y,lx,ly;
    int step,dir;
    bool out;
    
    x = 0;
    y = start;
    step = 1;
    d[x][y] = 0;
    out = false;
    while(true)
    {
        lx = x;
        ly = y;
        dir = getdir(a[x][y]);
        x += h[dir].x;
        y += h[dir].y;
        if(x < 0 || y < 0 || x >= nhang || y >= ncot)
        {
            out = true;
            break;
        }
        if(d[x][y] != -1)
            break;
        step++;
        d[x][y] = d[lx][ly] + 1;
    }
    if(out)
        printf("%d step(s) to exit\n",step);
    else
        printf("%d step(s) before a loop of %d step(s)\n",d[x][y],step-d[x][y]);
}
/**/
void input()
{
    int i,j;
    while(true)
    {
        scanf("%d %d %d",&nhang,&ncot,&start);
        if(!nhang && !ncot && !start)
            break;
        gets(a[0]);
        for(i=0;i<nhang;i++)
        {
            gets(a[i]);
            for(j=0;j<ncot;j++)
                d[i][j] = -1;
        }
        start--;
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
