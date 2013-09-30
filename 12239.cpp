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

#define fi "12239.inp"
#define fo "12239.out"
/**/
using namespace std;
/**/
int n,b;
int ball[100],d[100];
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
        d[i] = 0;
}
/**/
int absolute(int val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
void solve()
{
    int i,j;
    int temp;
    khoitao();
    
    for(i=1;i<b;i++)
        for(j=i-1;j>=0;j--)
        {
            temp = absolute(ball[i] - ball[j]);
            if(temp <= n)
                d[temp] = 1;
        }
    for(i=1;i<=n;i++)
        if(d[i] == 0)
        {
            printf("N\n");
            return;
        }
    printf("Y\n");
}
/**/
void input()
{
    int i;
    while(scanf("%d %d",&n,&b) == 2)
    {
        if(!n && !b)
            break;
        for(i=0;i<b;i++)
            scanf("%d",&ball[i]);
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
