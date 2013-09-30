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

#define fi "12318.inp"
#define fo "12318.out"
/**/
using namespace std;
/**/
long n,m;
int k;
long a[12];
int d[10000010];
/**/
void khoitao()
{
    long i;
    for(i=0;i<=n+2;i++)
        d[i] = 0;
}
void solve()
{
    long i;
    int j,bac;
    long long temp,tong,val;
    long dem;
    
    khoitao();
    dem = 0;
    for(i=0;i<=m;i++)
    {
        tong = 0;
        for(j=k;j>=0;j--)
        {
            bac = j;
            temp = 1;

            if(i != 1)
                while(bac--)
                {
                    temp *= i;
                    temp %= (n+1);
                }
            temp *= a[j] % (n+1);
            tong += temp;
            tong %= (n+1);
        }
        if(d[tong] == 0)        
        {
            d[tong] = 1;
            dem++;
        }
    }
    printf("%ld\n",dem);
}
/**/
void input()
{
    int i;
    while(scanf("%ld %ld",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        scanf("%d",&k);
        for(i=0;i<=k;i++)
            scanf("%ld",&a[i]);
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
