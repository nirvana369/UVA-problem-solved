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

#define fi "10104.inp"
#define fo "10104.out"
/**/
using namespace std;
/**/
void input()
{
    long a,b,r,x,y,x1,y1,x0,y0,nguyen;
    while(scanf("%ld %ld",&a,&b) == 2)
    {
        x0 = 1;
        x1 = 0;
        y0 = 0;
        y1 = 1;
        while(b != 0)
        {
            r = a % b;
            nguyen = a / b;
            x = x0 - x1 * nguyen;
            y = y0 - y1 * nguyen;
            a = b;
            b = r;
            x0 = x1;
            x1 = x;
            y0 = y1;
            y1 = y;
        }
        printf("%ld %ld %ld\n",x0,y0,a);
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
