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

#define fi "11678.inp"
#define fo "11678.out"
/**/
using namespace std;
/**/
long a[10010],b[10010];
int d[1000100],d1[1000100];
long alice,betty,da,db;
/**/
void khoitao()
{
    long i;
    for(i=0;i<100010;i++)
    {
        d[i] = 0;
        d1[i] = 0;
    }
    da = db = 0;
}
/**/
void input()
{
    long i;
    long temp,kq,chung;
    while(scanf("%ld %ld",&alice,&betty) == 2)
    {
        if(!alice && !betty)
            break;
        khoitao();
        for(i=0;i<alice;i++)
        {
            scanf("%ld",&temp);
            if(d[temp] == 0)
            {
                d[temp] = 1;
                a[da++] = temp;
            }
        }
        chung = 0;
        for(i=0;i<betty;i++)
        {
            scanf("%ld",&temp);
            if(d1[temp] == 0)
            {
                d[temp]++;
                if(d[temp] == 2)
                    chung++;
                d1[temp] = 1;
                b[db++]  = temp;
            }
        }
        kq = da-chung < db-chung ? da-chung : db - chung;
        printf("%ld\n",kq);
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
