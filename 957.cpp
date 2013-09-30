/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "957.inp"
#define fo "957.out"
/**/
using namespace std;
/**/
long p[100010];
long y,n;
/**/
long binsearch(long dau, long cuoi, long val)
{
    long giua;
    
    if(cuoi - dau <= 1)
    {
        if(p[cuoi] <= val)
            return cuoi;
        return dau;
    }
    
    giua = ( dau + cuoi ) / 2;
    
    if(p[giua] <= val)
        return binsearch(giua,cuoi,val);
    else
        return binsearch(dau,giua,val);
}
/**/
void solve()
{
    long l,h,kq,tmp;
    long i;
        
    kq = 0;
    
    for(i=1;i<=n;i++)
    {
        tmp = binsearch(i,n,p[i]+y-1);
        if(tmp - i + 1 > kq)
        {
            kq = tmp - i + 1;
            l = i;
            h = tmp;
        }
    }
    printf("%ld %ld %ld\n",kq,p[l],p[h]);
}
/**/
void input()
{
    long i;
    
    while(scanf("%ld",&y) == 1)
    {
        scanf("%ld",&n);
        
        for(i=1;i<=n;i++)
            scanf("%ld",&p[i]);
            
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
