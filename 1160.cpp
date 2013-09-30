/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1160.inp"
#define fo "1160.out"
/**/
using namespace std;
/**/
long pre[100010];
/**/
long fpre(long x)
{
    while(x != pre[x])
        x = pre[x];
    return x;
}
/**/
void khoitao()
{
    long i;
    for(i=0;i<100001;i++)
        pre[i] = i;
}
/**/
void input()
{
    long a,b,ida,idb;
    long refu;

    while(true)
    {
        a = -1;
        scanf("%ld",&a);
        if(a < 0)
            break;
        khoitao();
        refu = 0;
        while(a != -1)
        {
            scanf("%ld",&b);
            ida = fpre(a);
            idb = fpre(b);
            if(ida == idb)
                refu++;
            else
                pre[idb] = ida;
            scanf("%ld",&a);
        }
        printf("%ld\n",refu);
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
