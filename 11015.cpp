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

#define fi "11015.inp"
#define fo "11015.out"
#define maxgt 32000
/**/
using namespace std;
/**/
char name[25][100];
int a[25][25],d[25],q[25];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = maxgt;
        d[i] = 0;    
    }
}
/**/
int loang(int xp)
{
    int dau,cuoi;
    int i;
    int val;
    dau = -1;
    cuoi = 0;
    d[xp] = 1;
    q[0] = xp;
    val = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(a[q[dau]][i] != maxgt && d[i] == 0)
            {
                val += a[q[dau]][i];
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
            }
    }
    
    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
    if(!cuoi)
        return maxgt;
    return val;
}
/**/
void solve()
{
    int i,j,k;
    int temp,maxlen,id;
    
    for(i=1;i<=n;i++)                                       // floyd 
        for(j=1;j<=n;j++)
            if(j != i)
                for(k=1;k<=n;k++)
                    if(i != k && j != k)
                        if(a[i][k] + a[k][j] < a[i][j])
                        {
                            a[i][j] = a[i][k] + a[k][j];
                            a[j][i] = a[i][j];
                        }
    maxlen = maxgt;
    id = 1;
    for(i=1;i<=n;i++)                                   // loang
    {
        temp = loang(i);
        if(temp < maxlen)
        {
            maxlen = temp;
            id = i;
        }
    }
    printf("%s\n",name[id]);
}
/**/
void input()
{
    int i,id;
    int x,y,val;
    int m;
    id = 1;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        for(i=1;i<=n;i++)
            scanf("%s",&name[i]);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&val);
            a[x][y] = val;
            a[y][x] = val;
        }
        printf("Case #%d : ",id++);
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
