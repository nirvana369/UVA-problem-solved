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

#define fi "12205.inp"
#define fo "12205.out"
/**/
using namespace std;
/**/
struct hptime{
                long start,end;
            };
hptime a[11000];
int n,m;
void input()
{
    int i,j;
    long dau,s1,s2,dur;
    int dem;
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld %ld %ld",&s1,&s2,&a[i].start,&dur);
            a[i].end = a[i].start + dur;
        }
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld",&dau,&dur);
            dem = 0;
            for(j=0;j<n;j++)
                if((dau > a[j].start && dau < a[j].end) || (dau + dur > a[j].start && dau + dur < a[j].end) || (dau <= a[j].start && dau + dur >= a[j].end))
                    dem++;
            printf("%d\n",dem);
        }
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
