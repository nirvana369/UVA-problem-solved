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
#include <vector>

#define fi "1121.inp"
#define fo "1121.out"
/**/
using namespace std;
/**/
int a[100010];
/**/
void input()
{
    long i;
    long l,dau,n,m;
    long tong,tong1;
    while(scanf("%ld %ld",&n,&m) == 2)
    {
        tong = tong1 = 0;
        dau = 0;
        l = n;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            tong += a[i];
            tong1 += a[i];
            if(tong == m)
            {
                if(i - dau + 1 < l)
                    l = i - dau +1;
            }
            else if(tong > m)
            {
                while(tong - a[dau] >= m)
                    tong -= a[dau++];
                if(i-dau+1 < l)
                    l = i-dau+1;
            }
        }
        if(tong1 < m)
            printf("0\n");
        else
            printf("%ld\n",l);
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
