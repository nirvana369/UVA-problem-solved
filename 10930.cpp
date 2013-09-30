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

#define fi "10930.inp"
#define fo "10930.out"
/**/
using namespace std;
/**/
int n;
int a[32],d[31000];
bool asq;
/**/
void checka(int id,int sum)
{
    int i;
    if(sum == 0)
    {
        asq = false;
        return;
    }
    for(i=id;i>=0;i--)
    {
        if(sum - a[i] >= 0)
            checka(i-1,sum-a[i]);
        if(!asq)
            return;
    }
}
/**/
void solve()
{
    int i;
    for(i=n-1;i>=0;i--)
        checka(i-1,a[i]);
}
/**/
void output(int id)
{
    int i;
    printf("Case #%d:",id);
    for(i=0;i<n;i++)
        printf(" %d",a[i]);
    printf("\n");
    if(asq)
        printf("This is an A-sequence.\n");
    else
        printf("This is not an A-sequence.\n");
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<=30000;i++)
        d[i] = 0;
}
/**/
void input()
{
    int i;
    int id;
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        asq = true;
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i)
            {
                if(a[i] <= a[i-1])
                    asq = false;
            }
            d[a[i]] = 1;
        }
        if(asq)
            solve();
        output(id++);
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
