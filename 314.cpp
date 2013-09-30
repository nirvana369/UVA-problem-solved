/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "314.inp"
#define fo "314.out"
/**/
using namespace std;
/**/
struct data{
                int x,y;
                int kc;
                int dir;
            };
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
toado h1[4] = {0,0,
                -1,-1,
                -1,0,
                0,-1};
data q[4000];
data t;
toado kt;
bool d[55][55][5];
int a[55][55];
int nhang,ncot;
/**/
bool chk(int x,int y)
{
    int i;
    int px,py;
    
    for(i=0;i<4;i++)
    {
        px = x + h1[i].x;
        py = y + h1[i].y;
        if(a[px][py])
            return false;
    }
    return true;
}
/**/
int solve()
{
    int dau,cuoi;
    int i;
    data tmp;
    
    if(a[t.x][t.y])
        return -1;
        
    if(t.x == kt.x && t.y == kt.y)
        return 0;
        
    d[t.x][t.y][t.dir] = false;
    dau = -1;
    cuoi = 0;
    q[0] = t;
    
    while(dau != cuoi)
    {
        dau++;
        tmp = q[dau];
        
        // xoay phai
        t = tmp;
        t.kc = tmp.kc + 1; // 
        
        t.dir = (tmp.dir + 1) % 4;
        if(d[t.x][t.y][t.dir])
        {
            cuoi++;
            d[t.x][t.y][t.dir] = false;
            q[cuoi] = t;
        }
        
        // xoay trai
        t.dir = (tmp.dir + 3) % 4;
        
        if(d[t.x][t.y][t.dir])
        {
            cuoi++;
            d[t.x][t.y][t.dir] = false;
            q[cuoi] = t;
        }
        // go
        t.dir = tmp.dir;        
        for(i=1;i<4;i++)
        {
            t.x = tmp.x + h[t.dir].x * i;
            t.y = tmp.y + h[t.dir].y * i;
            
            if((t.x <= 0 || t.y <= 0 || t.x >= nhang || t.y >= ncot) || !chk(t.x,t.y))
                break;
            if(d[t.x][t.y][t.dir])
            {
                if(t.x == kt.x && t.y == kt.y)
                    return t.kc;
                cuoi++;
                d[t.x][t.y][t.dir] = false;
                q[cuoi] = t;
            }
        }
    }
    return -1;
}
/**/
int getdir(char c)
{
    if(c == 'n')
        return 0;
    if(c == 's')
        return 2;
    if(c == 'w')
        return 3;
    return 1;
}
/**/
void input()
{
    int i,j,k;
    char s[100];
    
    while(scanf("%d %d",&nhang,&ncot))
    {
        if(!nhang && !ncot)
            break;
            
        for(i=0;i<nhang;i++)
            for(j=0;j<ncot;j++)
            {
                scanf("%d",&a[i][j]);
                for(k=0;k<4;k++)
                    d[i][j][k] = true;
            }
            
        scanf("%d %d %d %d %s",&t.x,&t.y,&kt.x,&kt.y,&s);

        t.kc = 0;
        t.dir = getdir(s[0]);
        printf("%d\n",solve());
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
