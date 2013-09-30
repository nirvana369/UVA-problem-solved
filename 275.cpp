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

#define fi "275.inp"
#define fo "275.out"
/**/
using namespace std;
/**/
int vt[1100];
int du[11100],nguyen[11100];
int a,b;
/**/
void solve()
{
    int i,j;
    int dem,kq;
    int gt,gap;
    
    if(a > b)
        a %= b;
    dem = 0;
    while(true)
    {
        du[dem] = a;
        if(vt[a] != -1 || a == 0)       
        {
            kq = dem - vt[a];
            gt = a;
            break;
        }
        else
            vt[a] = dem++;
        if(a < b)   
            a *= 10;
        nguyen[dem-1] = a/b;
        a = a % b;
        //du[dem-1] = a;
    }
    gap = 0;
    j = 1;
    for(i=0;i<dem;i++,j++)
    {
        if(gt == du[i])
        {
            gap++;
            if(!gt && gap)
                break;
            if(gap == 2)
            {
                break;
            }
        }
        if(j % 50 == 0)
            printf("\n");
        printf("%d",nguyen[i]);
    }
    printf("\n");
    if(gt != 0)
        printf("The last %d digits repeat forever.\n\n",kq);
    else
        printf("This expansion terminates.\n\n");
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<=1000;i++)
        vt[i] = -1;
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d",&a,&b);
        if(!a && !b)
            break;
        khoitao();
        printf(".");
        if(a % b == 0)
            printf("\nThis expansion terminates.\n\n");
        else
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
