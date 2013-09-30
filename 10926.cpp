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

#define fi "10926.inp"
#define fo "10926.out"
/**/
using namespace std;
/**/
int q[110],d[110],a[110][110];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
int loang(int xp)
{
    int i;
    int dau,cuoi;
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    d[xp] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
            }
    }
    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
    return cuoi;
}
/**/
void solve()
{
    int i;
    int id,dep,temp;
    dep = 0;
    for(i=1;i<=n;i++)
    {
        temp = loang(i);
        if(temp > dep)
        {
            dep = temp;
            id = i;
        }
    }
    printf("%d\n",id);
}
/**/
void input()
{
    int i,j,k;
    int t;
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        khoitao();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            for(j=0;j<t;j++)
            {
                scanf("%d",&k);
                a[i][k] = 1;
            }
        }
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
