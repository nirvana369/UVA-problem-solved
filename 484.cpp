/*
                                                    Hoang Linh
                                                    
                                    Problem: THE DEPARTMENT OF REDUNDANCY DEPARTMENT (484.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "484.inp"
#define fo "484.out"
/**/
using namespace std;
/**/
long maxn;
long a[1000000];
int f[1000000];
/**/
bool kiemtra(long value)
{
    long i;
    for(i=0;i<maxn;i++)
        if(value == a[i])
        {
            f[i]++;
            return false;
        }
    return true;
}
/**/
void output()
{
    long i;
    for(i=0;i<maxn;i++)
        printf("%ld %d\n",a[i],f[i]);
}
/**/
void input()
{
    long temp;
    maxn = 0;
    while(scanf("%ld",&temp) == 1)
    {
        if(kiemtra(temp))
        {
            a[maxn] = temp;
            f[maxn] = 1;
            maxn++;
        }
    }
    output();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
