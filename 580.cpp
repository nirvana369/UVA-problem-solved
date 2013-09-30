/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "580.inp"
#define fo "580.out"
/**/
using namespace std;
/**/
long long u[100],e2[100];
/**/
void khoitao()
{
    int i;
    for(i=0;i<70;i++)
        e2[i] = u[i] = -1;
    e2[0] = 1;
    u[1] = 2;
    u[2] = 4;
    u[3] = 7;
}
/**/
long long cm(int lvl)
{
    if(u[lvl] == -1)
        u[lvl] = cm(lvl-1) + cm(lvl-2) + cm(lvl-3);
    return u[lvl];
}
/**/
long long _exp2(int lvl)
{
    if(e2[lvl] == -1)
        e2[lvl] = 2 * _exp2(lvl-1);
    return e2[lvl];
}
/**/
void input()
{
    int n;
    khoitao();
    while(scanf("%d",&n) && n)
        printf("%lld\n",_exp2(n) - cm(n));
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
