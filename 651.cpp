/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "651.inp"
#define fo "651.out"
/**/
using namespace std;
/**/
double len[100010];
/**/
void precal()
{
    long i;
    long tmp;
    tmp = 2;
    len[0] = 0;
    for(i=1;i<100000;i++,tmp+=2)
        len[i] += len[i-1] + 1.0/tmp;
}
/**/
void input()
{
    int n;
    precal();
    printf("# Cards Overhang\n");
    while(scanf("%d",&n) == 1)
        printf("%5ld     %0.3lf\n",n,len[n]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
