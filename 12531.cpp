/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12531.inp"
#define fo "12531.out"
/**/
using namespace std;
/**/
int _abs(int val)
{
    if(val < 0)
        val = -val;
    if(val > 180)
        val = 360 - val;
    return val;
}
/**/
void input()
{
    int i,j;
    int h,m,angle,n;
    bool match;
    
    while(scanf("%d",&n) == 1)
    {
        match = false;
        for(i=1;i<13;i++)
        {
            for(j=1;j<61;j++)
            {
                h = i * 30;
                m = j * 6;
                angle = _abs(h-m);
                if(angle == n)
                {
                    match = true;
                    break;
                }
            }
            if(match)
                break;
        }
        if(match)
            printf("Y\n");
        else
            printf("N\n");
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
