/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10341.inp"
#define fo "10341.out"
/**/
using namespace std;
/**/
double p,q,r,s,t,u;
/**/
double bt(double x)
{
      return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
/**/
void solve_it()
{
    double h,l,m;
    h = 1.0;
    l = 0.0;
    while(h - l > 1e-7)
    {
        m = (l+h) / 2;
        if(bt(m) * bt(l) <= 0)
            h = m;
        else
            l = m;
    }
    printf("%0.4lf\n",(h+l)/2);
}
/**/
void input()
{
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u) == 6)
    {
        if(bt(0) * bt(1) > 0)
            printf("No solution\n");
        else
            solve_it();
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
