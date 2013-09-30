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

#define fi "341.inp"
#define fo "341.out"
/**/
using namespace std;
/**/
long nhan[20];
int a[20][20],d[20],truoc[20];
int n;
/**/
int timnhan()
{
    int i,vt;
    long val;
    
    val = 3200000;
    
    for(i=1;i<=n;i++)
        if(d[i] == 0 && nhan[i] < val)
        {
            val = nhan[i];
            vt = i;
        }
    return vt;
}
/**/
void gannhan(int xp)
{
    int i;
    for(i=1;i<=n;i++)
        if(nhan[xp] + a[xp][i] < nhan[i])
        {
            nhan[i] = nhan[xp] + a[xp][i];
            truoc[i] = xp;
        }
}
/**/
void solve(int id)
{
    int dau,cuoi;
    int io,i;
    int dem;
    
    scanf("%d %d",&dau,&cuoi);
    nhan[dau] = 0;
    do
    {
        io = timnhan();
        if(io == cuoi)
            break;
        d[io] = 1;
        gannhan(io);
    }
    while(io != cuoi);
    
    printf("Case %d: Path =",id);
    dem = 0;
    while(io != dau)
    {
        d[dem++] = io;
        io = truoc[io];
    }
    d[dem] = io;
    for(i=dem;i>=0;i--)
        printf(" %d",d[i]);
    printf("; %ld second delay\n",nhan[cuoi]);
}
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 32000;
        nhan[i] = 32000;
        d[i] = 0;
    }
}
/**/
void input()
{
    int i,j;
    int id,m,p,dl;
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        khoitao();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d %d",&p,&dl);
                a[i][p] = dl;
            }
        }
        solve(id++);
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
