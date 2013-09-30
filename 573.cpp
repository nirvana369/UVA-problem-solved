/*
                                                    Hoang Linh
                                                    
                                            Problem: THE SNAIL - 573 (573.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "573.inp"
#define fo "573.out"
/**/
using namespace std;
/**/
float clim,h,slide,hs;
/**/
void solve()
{
    float heso,leo;
    int day;
    heso = clim * hs / 100;
    leo = 0;
    day = 1;
    
    while(true)
    {
        leo = leo + clim;
        if(leo > h)
            break;
        leo = leo - slide;
        if(leo < 0)
            break;
        clim = clim - heso;
        if(clim < 0)
            clim = 0;
        day++;
    }
    if(leo > h)
        printf("success on day %d\n",day);
    else
        printf("failure on day %d\n",day);
}
/**/
void input()
{
    while(true)
    {
        scanf("%f %f %f %f",&h,&clim,&slide,&hs);
        if(h == 0 && clim == 0 && slide == 0 && hs == 0)
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
