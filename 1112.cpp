/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1112.inp"
#define fo "1112.out"
/**/
using namespace std;
/**/
int a[110][110];
int n,m,t,dich;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 10000;
    }
}
/**/
void loang()
{
    int i,j,k;
    int dem;
    
    dem = 0;
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                    a[i][j] = min(a[i][k] + a[k][j],a[i][j]);
    
    for(i=1;i<=n;i++)
        if(a[i][dich] <= t || (i == dich))
            dem++;
            
    printf("%d\n",dem);
}
/**/
void input()
{
    int i;
    int x,y,tg;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&n,&dich,&t);
        khoitao();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&tg);
            a[x][y] = tg;
        }
        loang();
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
