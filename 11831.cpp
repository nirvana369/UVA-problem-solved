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

#define fi "11831.inp"
#define fo "11831.out"
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
toado vt;
int nhang,ncot,str;
int dir;
char s[50100],a[110][110];
/**/
void xuly(int hang,char s1[])
{
    int i;
    for(i=0;i<ncot;i++)
        if(s1[i] == 'N' || s1[i] == 'S' || s1[i] == 'L' || s1[i] == 'O')
        {
            vt.x = hang;
            vt.y = i;
            return;
        }
}
/**/
int getdir(char kt)
{
    if(kt == 'N')
        return 0;
    if(kt == 'S')
        return 2;
    if(kt == 'L')
        return 1;
    return 3;
}
/**/
void solve()
{
    int i;
    toado p;
    int dir,collect;
    
    dir = getdir(a[vt.x][vt.y]);
    i = 0;
    collect = 0;
    while(s[i] != 0)
    {
        if(s[i] == 'D')
        {
            dir++;
            if(dir > 3)
                dir = 0;
        }
        else if(s[i] == 'E')
        {
            dir--;
            if(dir < 0)
                dir = 3;
        }
        else
        {
            p.x = vt.x + h[dir].x;
            p.y = vt.y + h[dir].y;
            if(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot && a[p.x][p.y] != '#')
            {   
                if(a[p.x][p.y] == '*')
                {
                    collect++;
                    a[p.x][p.y] = '.';
                }
                vt = p;
            }
        }
        i++;
    }
    printf("%d\n",collect);
}
/**/
void input()
{
    int i;
    while(scanf("%d %d %d",&nhang,&ncot,&str))
    {
        if(!nhang && !ncot)
            break;
        vt.x = -1;
        for(i=0;i<nhang;i++)
        {
            scanf("%s",&a[i]);
            if(vt.x == -1)
                xuly(i,a[i]);
        }
        scanf("%s",&s);
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
