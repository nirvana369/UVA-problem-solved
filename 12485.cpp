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

#define fi "12485.inp"
#define fo "12485.out"
/**/
using namespace std;
/**/
long long tong;
long a[10100];
long n;
/**/
void solve()
{
    long i;
    long long val1,val2;
    
    val1 = val2 = 0;
    
    for(i=0;i<n;i++)
        if(a[i] > tong)
            val1 += a[i] - tong;
        else
            val2 += tong - a[i];
    if(val1 == val2)
        printf("%lld\n",val1+1);
    else
        printf("-1\n");
}
/**/
void input()
{
    long i;
    while(scanf("%ld",&n) == 1)
    {
        tong = 0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
            tong += a[i];
        }
        if(tong != 0)
            tong /= n;
        solve();
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
