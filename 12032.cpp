/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12032.inp"
#define fo "12032.out"
/**/
using namespace std;
/**/
long n;
long a[100100];
/**/
bool chk(long k)
{
    long i;
    for(i=1;i<=n;i++)
    {
        if(a[i] - a[i-1] > k)
            return false;
        else if(a[i] - a[i-1] == k)
            k--;
    }
    return true;
}
/**/
void input()
{
    long i;
    int ntest,id;
    long hi,lo,mid;
    
    scanf("%d",&ntest);
    id = 1;
    a[0] = 0;
    while(ntest--)
    {
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
            scanf("%ld",&a[i]);
        hi = 10000000;
        lo = 0;
        while(hi > lo)
        {
            mid = (hi+lo)/2;
            if(mid == hi || mid == lo)
                break;
            if(chk(mid))
                hi = mid;
            else
                lo = mid;
        }
        printf("Case %d: %ld\n",id++,(hi+lo)/2+1);
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
