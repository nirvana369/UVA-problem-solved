/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "1056.inp"
#define fo "1056.out"
/**/
using namespace std;
/**/
bool d[100],a[100][100];
int q[100],kc[100];
map<string,int > mmap;
int n;
bool connect;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = false;
        d[i] = true;
    }
    mmap.clear();
}
/**/
int loang(int xp)
{
    int i;
    int dau,cuoi;
    int dist;
    
    dau = -1;
    cuoi = 0;
    d[xp] = false;
    q[0] = xp;
    kc[0] = 0;
    
    dist = 0;
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(d[i] && a[q[dau]][i])
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = false;
                kc[cuoi] = kc[dau] + 1;
                
                if(kc[cuoi] > dist)
                    dist = kc[cuoi];
            }
    }
    if(cuoi +1 != n)
    {
        connect = false;
        return 0;
    }
    
    for(i=0;i<=cuoi;i++)
        d[q[i]] = true;
    
    return dist;
}
/**/
void solve()
{
    int i;
    int dist,tmp;
    
    dist = 0;
    connect = true;
    for(i=1;i<=n;i++)    
    {
        tmp = loang(i);
        if(!connect)
            break;
        if(tmp > dist)
            dist = tmp;
    }
    if(!connect)
        printf(" DISCONNECTED\n");
    else
        printf(" %d\n",dist);
    printf("\n");
}
/**/
void input()
{
    int i;
    int x,y;
    int m,r,id;
    char s[1000];
    
    id = 1;
    while(scanf("%d %d",&n,&r))
    {
        if(!n && !r)
            break;
        khoitao();
        m = 1;
        for(i=0;i<r;i++)
        {
            scanf("%s",&s);
            x = mmap[s];
            if(!x)
            {
                x = m;
                mmap[s] = m++;
            }
            
            scanf("%s",&s);
            y = mmap[s];
            if(!y)
            {
                y = m;
                mmap[s] = m++;
            }
            a[x][y] = a[y][x] = true;
        }
        printf("Network %d:",id++);
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
