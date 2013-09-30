/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "824.inp"
#define fo "824.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
            
toado h[8] = {0,1,
                -1,1,
                -1,0,
                -1,-1,
                0,-1,
                1,-1,
                1,0,
                1,1};
toado xp;
toado p[10];
int d[10];
int dir;
/**/
void solve()
{
    int i,j;
    
    toado pos;
    for(dir+=5,i = 0; i < 8; i++,dir++) 
    {
        dir %= 8;
        pos.x = xp.x + h[dir].x;
        pos.y = xp.y + h[dir].y;
        for(j=0;j<8;j++) 
        {
            if(p[j].x == pos.x && p[j].y == pos.y && d[j] == 1)
                break;
        }
        
        if(j != 8) 
        {
            printf("%d\n", dir);
            break;
        }
    }
}
/**/
void input()
{
    int i;
    
    while(true) 
    {
        scanf("%d",&xp.x);
        if(xp.x < 0)
            break;
        scanf("%d %d",&xp.y,&dir);
        
        for(i = 0; i < 8; i++)
            scanf("%d %d %d",&p[i].x,&p[i].y,&d[i]);
        
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
