/*
                                                Hoang Linh
                                                
                                    Problem: MEDIANS - 10347 (10347.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10347.inp"
#define fo "10347.out"
/**/
using namespace std;
/**/
void input()
{
    double p,kq,a,b,c;
    long temp;
    while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
    {
        p = (a + b + c) / 2;
        kq = (double)4/3 * (double)sqrt(p * (p - a) * (p - b) * (p - c));
        if(kq > 0)
            printf("%.3lf\n",kq);
        else
            printf("-1.000\n");
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
