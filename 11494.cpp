/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11494.inp"
#define fo "11494.out"
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
int x,y,xp,yp;
/**/
bool checkpos()
{
    int i;
    int px,py;

    for(i=0;i<8;i++)
    {
        px = x + h[i].x;
        py = y + h[i].y;
        
        while(px > 0 && px <= 8 && py >= 0 && py <= 8)
        {
            if(px == xp && py == yp)
                return true;
            px += h[i].x;
            py += h[i].y;
        }
    }
    return false;
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d %d %d",&x,&y,&xp,&yp);
        if(!x && !y && !xp && !yp)
            break;
        if(xp == x && y == yp)
            printf("0\n");
        else if(checkpos())
            printf("1\n");
        else
            printf("2\n");
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
