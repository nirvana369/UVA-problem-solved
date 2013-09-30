/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "12136.inp"
#define fo "12136.out"
/**/
using namespace std;
/**/
int dau,cuoi,dau1,cuoi1;
char s[10],e[10];
/**/
void chuyentg()
{
    int h,m;
    sscanf(s,"%d:%d",&h,&m);
    dau = h * 60 + m;
    sscanf(e,"%d:%d",&h,&m);
    cuoi = h * 60 + m;
}
/**/
void input()
{
    int ntest,id;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        printf("Case %d: ",id);
        scanf("%s %s",&s,&e);
        chuyentg();
        dau1 = dau;
        cuoi1 = cuoi;
        scanf("%s %s",&s,&e);
        chuyentg();
        if((dau1 <= dau && dau <= cuoi1) || (dau1 <= cuoi && cuoi <= cuoi1) || (dau <= dau1 && cuoi1 <= cuoi))
            printf("Mrs Meeting");
        else
            printf("Hits Meeting");
        printf("\n");
        id++;
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
