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

#define fi "1237.inp"
#define fo "1237.out"
/**/
using namespace std;
/**/
struct nfs{
            char name[30];
            long l,h;
          };
nfs a[10010];
int d[10010];
int ncar;
/**/
bool solve()
{
    int i;
    long price,xp;
    int vt;
    scanf("%ld",&price);
    xp = 0;
    for(i=0;i<ncar;i++)
        if(price >= a[i].l && price <= a[i].h)
        {
            xp++;
            vt = i;
        }
    if(xp == 1)
    {
        d[vt] = 1;
        printf("%s\n",a[vt].name);
        return false;
    }
    return true;
}
/**/
void input()
{
    int i;
    int ntest;
    int q;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&ncar);
        for(i=0;i<ncar;i++)
            scanf("%s %ld %ld",&a[i].name,&a[i].l,&a[i].h);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            if(solve())
                printf("UNDETERMINED\n");
        }
        if(ntest)
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
