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

#define fi "11835.inp"
#define fo "11835.out"
/**/
using namespace std;
/**/
int a[110][110],b[110],pnt[110];
int n,p;
/**/
void rs_point()
{
    int i;
    for(i=1;i<=p;i++)
        pnt[i] = 0;
}
/**/
void outp(int maxpnt)
{
    int i;
    bool space;
    space = false;
    for(i=1;i<=p;i++)
        if(pnt[i] == maxpnt)
        {
            if(!space)
                space = true;
            else
                printf(" ");
            printf("%d",i);
        }
    printf("\n");
}
/**/
void input()
{
    int i,j,k;
    int mp;
    int q,m;
    
    while(scanf("%d %d",&n,&p))
    {
        if(!n && !p)
            break;
        for(i=1;i<=n;i++)
            for(j=1;j<=p;j++)
                scanf("%d",&a[i][j]);
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%d",&m);
            for(j=1;j<=m;j++)
                scanf("%d",&b[j]);
            rs_point();
            mp = 0;
            for(j=1;j<=n;j++)
                for(k=1;k<=p;k++)
                    if(a[j][k] <= m)
                    {
                        pnt[k] += b[a[j][k]];
                        mp = pnt[k] > mp ? pnt[k] : mp;
                    }
            outp(mp);
        }
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
