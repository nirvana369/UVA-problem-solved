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

#define fi "12356.inp"
#define fo "12356.out"
/**/
using namespace std;
/**/
long trai[100100],phai[100100];
long l,r;
long n;
/**/
void khoitao()
{
    long i;
    for(i=1;i<=n;i++)
    {
        trai[i] = i-1;
        phai[i] = i+1;
    }
}
/**/
void input()
{
    long i;
    long rep;
    while(scanf("%ld %ld",&n,&rep) == 2)
    {
        if(!n && !rep)
            break;
        khoitao();
        for(i=0;i<rep;i++)
        {
            scanf("%ld %ld",&l,&r);
            if(trai[l] == 0)
                printf("* ");
            else
                printf("%d ",trai[l]);
            if(phai[r] == n+1)
                printf("*\n");
            else
                printf("%d\n",phai[r]);
            trai[phai[r]] = trai[l];
            phai[trai[l]] = phai[r];
        }
        printf("-\n");
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
