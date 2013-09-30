/*
                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10608.inp"
#define fo "10608.out"
/**/
using namespace std;
/**/
long n,m;
long truoc[40000],d[40000];
/**/
void khoitao()
{
    long i;
    for(i=1;i<=n;i++)
    {
        truoc[i] = i;
        d[i] = 1;
    }
}
/**/
void solve()
{
    long i,temp;
    long dem;
    dem = 0;
    for(i=1;i<=n;i++)
        if(i != truoc[i])
        {
            temp = i;
            while(temp != truoc[temp])
            {
                d[truoc[temp]] += d[temp];
                d[temp] = 0;
                temp = truoc[temp];
            }
        }
    for(i=1;i<=n;i++)
    {
        if(d[i] > dem)
            dem = d[i];
    }
    printf("%ld\n",dem);
}
/**/
void input()
{
    long i;
    int ntest;
    long x,y;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&n,&m);
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld",&x,&y);
            while(truoc[y] != y)
                y = truoc[y];
            while(truoc[x] != x)
                x = truoc[x];
            truoc[y] = x;
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
