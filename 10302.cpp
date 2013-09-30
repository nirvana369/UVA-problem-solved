#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10302.inp"
#define fo "10302.out"
/**/
using namespace std;
/**/
long long a[50100];
/**/
void precal()
{
    long i;
    a[0] = 0;
    for(i=1;i<=50000;i++)
        a[i] = (long long)i * i * i + a[i-1];
}
/**/
void input()
{
    long x;
    precal();
    while(scanf("%ld",&x) == 1)
        printf("%lld\n",a[x]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
