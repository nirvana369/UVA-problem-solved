/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10916.inp"
#define fo "10916.out"
/**/
using namespace std;
/**/
int year[1000];
int dy;
/**/
void _init()
{
    dy = 0;
    year[0] = 1960;
    while(year[dy] <= 2160)
    {
        dy++;
        year[dy] = year[dy-1] + 10;
    }
}
/**/
void input()
{
    int i;
    long tmp,dau,cuoi;
    int y;
    _init();
    while(scanf("%d",&y) && y)
    {
        dau = 1;
        cuoi = 2;
        for(i=0;i<dy;i++)
        {
            if(year[i] > y)
                break;
            tmp = cuoi;
            cuoi += dau;
            dau = tmp;
        }
        printf("%ld\n",cuoi);
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
