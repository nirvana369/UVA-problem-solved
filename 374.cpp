/*
                                                        Hoang Linh
                                                        
                                                Problem: BIG MOD - 374 (374.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "374.inp"
#define fo "374.out"
//
using namespace std;
//
long b,p,m;
//
long long dequy(long mu)
{
    long long gt;
    if(mu == 0)
        return 1;
    if(mu == 1)
        return b%m;
    gt = dequy(mu/2) % m;
    return (gt * gt * (dequy(mu%2) % m))%m;
}
//
void input()
{
    long long kq;
    while(scanf("%ld %ld %ld",&b,&p,&m) == 3)
    {
        kq = dequy(p);
        printf("%ld\n",kq);
    }
}
//
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
