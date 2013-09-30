/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10680.inp"
#define fo "10680.out"
/**/
using namespace std;
/**/
int lcm[1000010];
/**/
long long ucln(long long a,long long b)
{
    long long r;
    while(b != 0)
    {
        r = a % b;
        a =  b;
        b = r;
    }
    return a;
}
/**/
long long bcnn(long long a,long long b)
{
    return (a / ucln(a,b) * b);
}
/**/
int solve(long long val)
{
    while(val % 10 == 0)
        val /= 10;
    return (val % 1000);
}
/**/
/**/
void _init()
{
    long i,j;
    
    lcm[1] = 1;
    
    for(i=2;i<=1000000;i++)
    {
        lcm[i] = bcnn(lcm[i-1],i);
        lcm[i] = solve(lcm[i]);
    }
}
/**/
void input()
{
    long n;
    
    _init();
    while(scanf("%ld",&n) && n)
    {
        printf("%d\n",lcm[n]);
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
