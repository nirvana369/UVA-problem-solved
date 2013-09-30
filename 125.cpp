/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "125.inp"
#define fo "125.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado a[20000];
int d[110][110];
int m,n;
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            d[i][j] = 0;
            
    for(i=0;i<m;i++)
        d[a[i].x][a[i].y] = 1;
}
/**/
void solve()
{
    int i,j,k;
    khoitao();
    
    for(k=0;k<=n;k++)
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                if(d[i][k] && d[k][j])
                    d[i][j] += d[i][k] * d[j][k];
    
    for(k=0;k<=n;k++)
        if(d[k][k])
            for(i=0;i<=n;i++)
                for(j=0;j<=n;j++)
                    if(d[i][k] && d[k][j])
                        d[i][j] = -1;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j)
                printf(" ");
            printf("%d",d[i][j]);
        }
        printf("\n");
    }
}
/**/
void input()
{
    int i,id;
    id = 0;
    while(scanf("%d",&m) == 1)
    {
        n = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
            n = a[i].x > n ? a[i].x : n;
            n = a[i].y > n ? a[i].y : n;
        }
        printf("matrix for city %d\n",id++);
        solve();
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
