/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10246.inp"
#define fo "10246.out"
#define maxval 1000000000l
/**/
using namespace std;
/**/
long a[100][100];
int cost[100],mcost[100][100];
int n,r,q;
/**/
int maxcost(int gt1,int gt2)
{
    return (gt1 > gt2) ? gt1 : gt2;
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            a[i][j] = maxval;
            mcost[i][j] = maxcost(cost[i],cost[j]);
        }
}
/**/
void solve()
{
    int i,j,k;
    int tmp;
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                tmp = maxcost(mcost[i][k],mcost[k][j]);
                if(a[i][k] + a[k][j] + tmp <= a[i][j] + mcost[i][j]) // greedy
                {
                    a[i][j] = a[i][k] + a[k][j];
                    mcost[i][j] = tmp;
                }
            }
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                tmp = maxcost(mcost[i][k],mcost[k][j]);
                if(a[i][k] + a[k][j] + tmp <= a[i][j] + mcost[i][j]) // sua nhan toi uu
                {
                    a[i][j] = a[i][k] + a[k][j];
                    mcost[i][j] = tmp;
                }
            }
}
/**/
void input()
{
    int i;
    int x,y,gt;
    int id;
    id = 0;
    while(true)
    {
        scanf("%d %d %d",&n,&r,&q);
        if(!n && !r && !q)
            break;
        if(id++)
            printf("\n");
        
        for(i=1;i<=n;i++)
            scanf("%d",&cost[i]);
        khoitao();
        for(i=0;i<r;i++)
        {
            scanf("%d %d %d",&x,&y,&gt);
            a[x][y] = a[y][x] = gt;
        }
        solve();
        
        printf("Case #%d\n",id);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            if(a[x][y] != maxval)
                printf("%ld\n",a[x][y]+mcost[x][y]);
            else
                printf("-1\n");
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
