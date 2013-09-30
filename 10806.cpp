/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "10806.inp"
#define fo "10806.out"
#define maxgt 100000000
/**/
using namespace std;
/**/
bool d[110];
int trc[110];
queue<int > q;
long nhan[110],a[110][110];
int n;
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = maxgt;
}
/**/
void _reset()
{
    int i;
    
    for(i=1;i<=n;i++)
    {
        d[i] = true;
        nhan[i] = maxgt;
    }
}
/**/
long shortp(int xp,int kt)
{
    int i,io;
    
    while(!q.empty())
        q.pop();
        
    nhan[xp] = 0;
    q.push(xp);
    
    while(!q.empty())
    {
        io = q.front();
        q.pop();
        d[io] = false;
        for(i=1;i<=n;i++)
            if(nhan[io] + a[io][i] < nhan[i])
            {
                trc[i] = io;
                nhan[i] = nhan[io] + a[io][i];
                if(d[i])
                    q.push(i);
            }
    }
    
    if(nhan[kt] != maxgt)
    {
        io = kt;
        while(io != xp)
        {
            a[trc[io]][io] = -a[trc[io]][io];
            a[io][trc[io]] =  maxgt;
            io = trc[io];
        }
    }
    return nhan[kt];
}
/**/
void solve()
{
    long len,kq;
    
    _reset();
    
    kq = shortp(1,n);
    if(kq < maxgt)
    {
        _reset();
        kq += shortp(n,1);
    }
    
    if(kq < maxgt)
        printf("%ld\n",kq);
    else
        printf("Back to jail\n");
}
/**/
void input()
{
    int i;
    int x,y,t;
    int m;
    while(scanf("%d",&n) && n)
    {
        khoitao();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&t);
            a[x][y] = a[y][x] = t;
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

