/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10057.inp"
#define fo "10057.out"
#define maxn 65537
/**/
using namespace std;
/**/
long n;
long d[maxn+10];
/**/
void khoitao()
{
    long i;
    for(i=0;i<maxn;i++)
        d[i] = 0;
}
/**/
void solve()
{
    long i,j;
    long k,mid,dau,cuoi,dif,dem;
    
    if(n % 2 != 0)
        k = n / 2 + 1;
    else
        k = n / 2;
        
    dau = 0;
    for(i=0;i<maxn;i++)
        if(d[i])
        {
            cuoi = dau + d[i];
            if(k > dau && k <= cuoi)
            {
                mid = i;
                dem = d[i];
                dif = 1;

                if(n % 2 == 0)
                {
                    if(k+1 > cuoi)
                        for(j=i+1;j<maxn;j++)
                            if(d[j])
                            {
                                mid = i;
                                dem = d[i] + d[j];
                                dif = j-i+1;
                                break;
                            }
                }
                break;
            }
            dau = cuoi;
        }
    printf("%ld %ld %ld\n",mid,dem,dif);
}
/**/
void input()
{
    long i;
    long val;
    while(scanf("%ld",&n) == 1)
    {
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%ld",&val);
            d[val]++;
        }
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
