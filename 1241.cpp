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

#define fi "1241.inp"
#define fo "1241.out"
/**/
using namespace std;
/**/
int d[1100];
int n,m;
/**/
void khoitao()
{
    int i;
    n = 1 << n;
    for(i=1;i<=n;i++)
        d[i] = 1;
}
/**/
void input()
{
    int ntest;
    int i,j;
    int walk,vt;
    scanf("%d",&ntest);
    while(ntest--)
    {
        n = m = 0;
        scanf("%d %d",&n,&m);
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d",&vt);
            d[vt] = 0;
        }
        walk = 0;
        while(n != 1)
        {
            for(i=1,j=1;i<n;i+=2,j++)
                if(d[i] && d[i+1])
                    d[j] = d[i];
                else if(d[i] && !d[i+1] || !d[i] && d[i+1])
                {
                    walk++;
                    d[j] = 1;
                }
                else
                    d[j] = 0;
            n = j-1;
        }
        printf("%d\n",walk);
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
