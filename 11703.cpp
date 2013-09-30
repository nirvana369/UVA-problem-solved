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

#define fi "11703.inp"
#define fo "11703.out"
#define maxgt 1000000
/**/
using namespace std;
/**/
long x[maxgt+10];
/**/
void precal()
{
    long i,valsqrt,vallog,valsin;
    long temp;
    x[0] = 1;
    for(i=1;i<=maxgt;i++)
    {
        valsqrt = (int)floor(i-sqrt(i));
        vallog = (int)floor(log(i));
        valsin = (int)floor(i * sin(i) * sin(i));
        
        x[i] = x[valsqrt] + x[vallog] + x[valsin];
        x[i] %= maxgt;
    }
}
/**/
void input()
{
    long n;
    precal();
    while(scanf("%ld",&n) == 1)
    {
        if(n == -1)
            break;
        printf("%ld\n",x[n]);
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
