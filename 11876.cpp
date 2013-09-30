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

#define fi "11876.inp"
#define fo "11876.out"
/**/
using namespace std;
/**/
long a[120000],d[1000100],vt[1000100];
long da;
long dau,cuoi;
/**/
void precal()
{
    long i,j;
    long dem;
    for(i=1;i<=1000000;i++)
    {
        d[i] = 1;
        vt[i] = 0;
    }
    
    for(i=2;i<=1000000;i++)         // dem uoc
        for(j=i;j<=1000000;j+=i)
            d[j]++;
    da = 1;
    a[da++] = 1;
    vt[1] = -1;
    while(a[da-1] < 1000000)    
    {
        a[da++] = a[da-1] + d[a[da-1]];
        if(a[da-1] < 1000000)
            vt[a[da-1]] = -1;
    }
    dem = 0;
    for(i=1;i<=1000000;i++)
        if(vt[i] == -1)
        {
            d[i] = 1;
            vt[i] = dem;
            dem++;
        }
        else
        {
            d[i] = 0;
            vt[i] = dem;
        }
}
/**/
void input()
{
    long ntest,id;
    precal();
    id = 1;
    scanf("%ld",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&dau,&cuoi);
        printf("Case %ld: %ld\n",id++,vt[cuoi] + d[cuoi] - vt[dau]);
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
