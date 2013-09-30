/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10589.inp"
#define fo "10589.out"
/**/
using namespace std;
/**/
double r,a;
/**/
bool kiemtra(double x,double y)
{
    if(x * x + y * y > r)
        return false;
    if(x * x + (y-a) * (y-a) > r)
        return false;
    if((x-a) * (x-a) + y * y > r)
        return false;
    if((x-a) * (x-a) + (y-a) * (y-a) > r)
        return false;
    return true;
}
/**/
void input()
{
    long i;
    long n,dp,b;
    double kq,x,y;
    while(true)
    {
        scanf("%ld %ld",&n,&b);
        if(!n && !b)
            break;
        a = (double)b;
        r = a * a;
        dp = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&x,&y);
            if(kiemtra(x,y))
                dp++;
        }
        kq = (double)dp*a*a/n;
        printf("%.5lf\n",kq);
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
