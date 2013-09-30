/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12620.inp"
#define fo "12620.out"
/**/
using namespace std;
/**/
int f[310];
int cf;
/**/
void _init()
{
    int i;
    int f1,f2,f3;
    // cycle fibonaci modulo 100 
    f[1] = f1 = 1;
    f[2] = f2 = 1;
    cf = 3;
    for(cf=3;cf<301;cf++) // cycle 300 number
    {
        f[cf] = f1 + f2;
        if(f[cf] > 99)
            f[cf] %= 100;
        f1 = f2;
        f2 = f[cf];
    }
    for(i=2;i<cf;i++)
        f[i] += f[i-1];
    cf--;
}
/**/
void input()
{
    int i;
    int ntest;
    long long sum;
    long long x,y;
    long nguyen,du;
    
    _init();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lld %lld",&x,&y);
        nguyen = f[cf];
        du = f[y%cf];
        sum = y / cf * nguyen + du;
        
        x--;        
        du = f[x%cf];
        sum -= x / cf * nguyen + du;
        
        printf("%lld\n",sum);
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
