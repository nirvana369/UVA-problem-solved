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

#define fi "11068.inp"
#define fo "11068.out"
/**/
using namespace std;
/**/
int d1[4],d2[4];
/**/
void solve()
{
    float d,dx,dy;
    d = (float)(d1[0] * d2[1]) - (d2[0] * d1[1]);
    dx = (float)(d1[1] * d2[2]) - (d2[1] * d1[2]);
    dy = (float)(d1[2] * d2[0]) - (d2[2] * d1[0]);
    if(d != 0)
    {
        dx = dx / d;
        dy = dy / d;
        dx *= -1;
        dy *= -1;
        printf("The fixed point is at %0.2f %0.2f.\n",dx,dy);
    }
    else
        printf("No fixed point exists.\n");
}
/**/
void input()
{
    int i;
    while(true)
    {
        for(i=0;i<3;i++)
            scanf("%d",&d1[i]);
        for(i=0;i<3;i++)
            scanf("%d",&d2[i]);
        if(d1[0] == 0 && d1[1] == 0 && d1[2] == 0 && d2[0] == 0 && d2[1] == 0 && d2[2] == 0)
            break;
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
