/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12068.inp"
#define fo "12068.out"
/**/
using namespace std;
/**/
long long ucln(long long a,long long b)
{
    long long r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**/
long long bcnn(long long a,long long b)
{
    a /= ucln(a,b);
    a *= b;
    return a;
}
/**/
void input()
{
    int i;
    int ntest,id;
    long long mul,tu,mau,tmp;
    int a[110];
    int n;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        mul = 1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mul = bcnn(mul,a[i]);
        }
        mau = 0;
        for(i=0;i<n;i++)
            mau += mul / a[i];
        tu = mul * n;
        tmp = ucln(tu,mau);
        tu /= tmp;
        mau /= tmp;
        printf("Case %d: %lld/%lld\n",id++,tu,mau);
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
