/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10014.inp"
#define fo "10014.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    double a0,an,a1,sum;
    double c[3010];
    int n;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %lf %lf",&n,&a0,&an);
        for(i=0;i<n;i++)
            scanf("%lf",&c[i]);
        sum = 0;
        for(i=0;i<n;i++)
            sum += c[i] * 2 * (n-i);
        a1 = (n * a0 + an - sum) / (n + 1);
        printf("%.2lf\n",a1);
        if(ntest)
            printf("\n");
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
