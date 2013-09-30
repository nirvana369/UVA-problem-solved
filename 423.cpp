/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "423.inp"
#define fo "423.out"
/**/
using namespace std;
/**/
long nhan[110];
int d[110],a[110][110];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 32760;
        nhan[i] = 5000000;
        d[i] = 0;
    }
}
/**/
int timnhan()
{
    int i;
    long maxgt;
    int vt;
    
    maxgt = 5000000;
    for(i=1;i<=n;i++)
        if(d[i] == 0 && nhan[i] < maxgt)
        {
            maxgt = nhan[i];
            vt = i;
        }
    return vt;
}
/**/
void gannhan(int xp)
{
    int i;
    for(i=1;i<=n;i++)
        if(d[i] == 0 && nhan[xp] + a[xp][i] < nhan[i])
            nhan[i] = nhan[xp] + a[xp][i];
}
/**/
void solve()
{
    int io,i;
    int p;
    long value;
    
    nhan[1] = 0;
    p = n;
    while(p != 0)
    {
        io = timnhan();
        d[io] = 1;
        gannhan(io);
        p--;
    }
    value = 0;
    for(i=1;i<=n;i++)
        if(nhan[i] > value)
            value = nhan[i];
    printf("%ld\n",value);
}
/**/
void input()
{
    int i,j;
    char temp[100];
    
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        khoitao();
        for(i=2;i<=n;i++)
            for(j=1;j<i;j++)
            {
                scanf("%s",&temp);
                if(temp[0] != 'X')
                {
                    sscanf(temp,"%d",&a[i][j]);
                    a[j][i] = a[i][j];
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
