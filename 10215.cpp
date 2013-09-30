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

#define fi "10215.inp"
#define fo "10215.out"
/**/
using namespace std;
/**/
void input()
{
    double a,b,kq1,kq2,kq3;
    while(scanf("%lf %lf",&a,&b) == 2)
    {
        kq1 = ((a+b) - sqrt((a+b) * (a+b) - 3*a*b)) / 6;
        kq2 = 0;
        kq3 = (a > b ? b : a) / 2;
        printf("%0.3lf %0.3lf %0.3lf\n",kq1+1e-7,kq2+1e-7,kq3+1e-7);
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
