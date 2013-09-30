/*
                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10583.inp"
#define fo "10583.out"
/**/
using namespace std;
/**/
long n,m;
long truoc[60000],d[60000];
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
        if(d[i] != 0)
            dem++;
    printf("%ld\n",dem);
}
/**/
void input()
{
    long i;
    int id;
    long x,y;
    
    id = 1;
    while(true)
    {
        scanf("%ld %ld",&n,&m);
        if(!n && !m)
            break;
        khoitao();
        printf("Case %d: ",id);
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld",&x,&y);
            while(truoc[y] != y)
            {
                d[truoc[y]] += d[y];
                y = truoc[y];
            }
            while(truoc[x] != x)
            {
                d[truoc[x]] += d[x];
                x = truoc[x];
            }
            truoc[y] = x;
        }
        solve();
        id++;
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
