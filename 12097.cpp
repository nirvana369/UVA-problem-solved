/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12097.inp"
#define fo "12097.out"
/**/
using namespace std;
/**/
double a[10010];
int n;
double f;
/**/
bool chk(double val)
{
    int i;
    double gt;
    
    gt = 0;
    for(i=0;i<n;i++)
        gt += floor(a[i]/val);
    return (gt <= f);
}
/**/
void input()
{
    int i;
    int ntest;
    double m,kt,xp,pi;
    
    pi = acos(-1);
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %lf",&n,&f);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            a[i] = pow(a[i],2) * pi;
        }
        kt = 1e10;
        xp = 0;
        while(kt - xp > 1e-7)
        {
            m = (kt + xp) / 2;
            if(chk(m))
                kt = m;
            else
                xp = m;
        }
        printf("%0.4lf\n",(kt + xp) / 2);
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
