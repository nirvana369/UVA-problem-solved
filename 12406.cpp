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

#define fi "12406.inp"
#define fo "12406.out"
/**/
using namespace std;
/**/
int len;
long long n,firstnum,lastnum;
bool ip;
/**/
void dq(int j,long long val)
{
    int i;
    if(j == len)
    {
        if(val % n == 0)
        {
            if(ip)
            {
                firstnum = val;
                printf(" %lld",val);
            }
            lastnum = val;
            ip = false;
        }
        return;
    }
    for(i=1;i<=2;i++)
        dq(j+1,val*10+i);
}
/**/
void input()
{
    int ntest,id;
    int mu;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&len,&mu);
        n = 1 << mu;
        ip = true;
        printf("Case %d:",id++);
        dq(0,0);
        if(!ip)
        {
            if(firstnum != lastnum)
                printf(" %lld",lastnum);
        }
        else
            printf(" impossible");
        printf("\n");
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
