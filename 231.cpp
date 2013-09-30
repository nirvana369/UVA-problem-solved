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

#define fi "231.inp"
#define fo "231.out"
/**/
using namespace std;
/**/
int a[30000],d[30000];
int da;

/**/
void solve()
{
    int i,j;
    int maxgt;
    maxgt = 0;
    for(i=1;i<da;i++)
        for(j=i-1;j>=0;j--)
            if(a[i] <= a[j] && d[i] <= d[j])
            {
                d[i] = d[j] + 1;
                if(d[i] > maxgt)
                    maxgt = d[i];
            }
    printf("  maximum possible interceptions: %d\n",maxgt);
}
/**/
void input()
{
    int id;
    id = 0;
    while(true)
    {
        da = 0;
        scanf("%d",&a[da]);
        if(a[da] == -1)
            break;
        if(id)
            printf("\n");
        d[0] = 1;
        while(a[da] != -1)
        {
            da++;
            d[da] = 1;
            scanf("%d",&a[da]);
        }
        printf("Test #%d:\n",++id);
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
