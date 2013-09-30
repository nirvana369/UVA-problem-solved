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

#define fi "11057.inp"
#define fo "11057.out"
/**/
using namespace std;
/**/
long long a[10010];
int d[1001010];
int n;
/**/
long long ttd(long long hieu)
{
    if(hieu < 0)
        return -hieu;
    return hieu;
}
/**/
void khoitao()
{
    long i;
    for(i=0;i<1000101;i++)
        d[i] = 0;
}
/**/
void solve()
{
    int i;
    long long m,dif,x,y,temp;
    scanf("%lld",&m);
    dif = m + 2;
    if(m % 2 == 0 && d[m/2] >= 2)
    {
        x = m/2;
        y = m/2;
    }
    else
        for(i=0;i<n;i++)
        {
            temp = m - a[i];
            if(temp < 1000001 && temp >= 0)
                if(d[temp] >= 1 && ttd(temp-a[i]) < dif)
                {
                    if(a[i] < temp)
                    {
                        x = a[i];
                        y = temp;
                        dif = temp - a[i];
                    }
                    else
                    {
                        y = a[i];
                        x = temp;
                        dif = a[i] - temp;
                    }
                }
        }
    printf("Peter should buy books whose prices are %lld and %lld.\n\n",x,y);
}
/**/
void input()
{
    int i;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            d[a[i]]++;
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
