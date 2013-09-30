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

#define fi "12290.inp"
#define fo "12290.out"
/**/
using namespace std;
/**/
int a[222],d[111];
int n,m,k,da;
/**/
void khoitao()
{
    int i;
    da = 0;
    for(i=1;i<=n;i++)
    {
        a[da++] = i;
        d[i] = 0;
    }
    for(i=n-1;i>1;i--)
        a[da++] = i;
}
/**/
bool kiemtra(long val)
{
    while(val != 0)
    {
        if(val % 10 == 7)
            return true;
        val /= 10;
    }
    return false;
}
/**/
void solve()
{
    int i;
    long dem;
    dem = 1;
    i = 0;
    while(true)
    {
        if(dem % 7 == 0 || kiemtra(dem))
            d[a[i]]++;
        if(d[m] == k)
            break;
        dem++;
        i++;
        if(i == da)
            i = 0;
    }
    printf("%ld\n",dem);
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d %d",&n,&m,&k);
        if(!n && !m && !k)
            break;
        khoitao();
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
