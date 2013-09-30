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

#define fi "10354.inp"
#define fo "10354.out"
#define maxgt 32766
/**/
using namespace std;
/**/
int a[110][110],d[110],b[110][110];
int n,nroad,pboss,poff,yhome,smarket;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            a[i][j] = a[j][i] = maxgt;
            b[i][j] = b[j][i] = maxgt;
        }
        d[i] = 0;
        a[i][i] = b[i][i] = 0;; 
    }
}
/**/
int solve()
{
    int i,j,k;
    // floyd 
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] + a[k][j] < a[i][j])   // tim duong ngan nhan tu boss home -- > office
                    a[i][j] = a[i][k] + a[k][j];
    
    for(i=1;i<=n;i++)           // danh dau nhung noi boss di qua
        if(a[pboss][i] + a[i][poff] == a[pboss][poff])
            d[i] = 1;
    d[pboss] = 1;
    d[poff] = 1;
    
    for(k=1;k<=n;k++)       // tim duong ngan nhat tu home -- >  market neu co
        if(!d[k])
            for(i=1;i<=n;i++)
                if(!d[i])
                    for(j=1;j<=n;j++)
                        if(!d[j])
                            if(b[i][k] + b[k][j] < b[i][j])
                                b[i][j] = b[i][k] + b[k][j];
    if(b[yhome][smarket] == maxgt || d[yhome] || d[smarket])
        return -1;
    return b[yhome][smarket];
}
/**/
void input()
{
    int i;
    int x,y;
    int cost,kq;
    while(scanf("%d %d %d %d %d %d",&n,&nroad,&pboss,&poff,&yhome,&smarket) == 6)
    {
        khoitao();
        for(i=0;i<nroad;i++)
        {
            scanf("%d %d %d",&x,&y,&cost);
            a[x][y] = a[y][x] = cost;
            b[x][y] = b[y][x] = cost;
        }
        kq = solve();
        if(kq == -1)
            printf("MISSION IMPOSSIBLE.\n");
        else
            printf("%d\n",kq);
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
