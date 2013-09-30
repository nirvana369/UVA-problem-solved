/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11926.inp"
#define fo "11926.out"
/**/
using namespace std;
/**/
long dau,cuoi;
int n,m;
bool d[1000010];
bool cf;
/**/
void solve()
{
    long i;
    
    if(cf)
        return;
    
    for(i=dau;i<cuoi;i++)
        if(d[i])
        {
            cf = true;
            return;
        }
        else
            d[i] = true;
}
/**/
void swapi(long a,long b)
{
    long tmp;
    tmp = a;
    a = b;
    b = tmp;
}
/**/
void khoitao()
{
    long i;
    for(i=0;i<=1000000;i++)
        d[i] = false;
    cf = false;
}
/**/
void input()
{
    int i;
    long rep;
    
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld",&dau,&cuoi);
            if(dau > cuoi)
                swapi(dau,cuoi);
            solve();
        }
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %ld",&dau,&cuoi,&rep);
            if(dau > cuoi)
                swapi(dau,cuoi);
            if(!cf)
                while(true)
                {
                    solve();
                    dau += rep;
                    cuoi += rep;
                    if(dau > 1000000)
                        break;
                    if(cuoi > 1000000)
                        cuoi = 1000000;
                }
        }
        if(cf)
            printf("CONFLICT\n");
        else
            printf("NO CONFLICT\n");
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
