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

#define fi "11088.inp"
#define fo "11088.out"
/**/
using namespace std;
/**/
int d[20],a[20];
int n,ft;
/**/
void dq(int id)
{
    int i,j,k;
    if(id > ft)
        ft = id;
        
    for(i=0;i<n-2;i++)
        if(!d[i])
            for(j=i+1;j<n-1;j++)
                if(!d[j])
                    for(k=j+1;k<n;k++)
                        if(!d[k] && a[i] + a[j] + a[k] >= 20)
                        {
                            d[i] = d[j] = d[k] = 1;
                            dq(id+1);
                            if(ft == n/3)
                                return;
                            d[i] = d[j] = d[k] = 0;
                        }
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            d[i] = 0;
        }
        ft = 0;
        dq(0);
        printf("Case %d: %d\n",id++,ft);
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
