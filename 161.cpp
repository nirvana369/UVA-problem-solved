/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "161.inp"
#define fo "161.out"
/**/
using namespace std;
/**/
int a[110],d[19000];
int dl;
/**/
void sapxep()
{
    int i;
    int temp;
    
    for(i=1;i<dl;i++)
        if(a[0] > a[i])
        {
            temp = a[0];
            a[0] = a[i];
            a[i] = temp;
        }
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<=18000;i++)
        d[i] = 0;
    for(i=0;i<a[0]*2;i++)
        d[i] = 1;
}
/**/
void output(int tg)
{
    int h,m,s;
    s = tg % 60;
    tg = tg / 60;
    m = tg % 60;
    h = tg / 60;
    printf("%02d:%02d:%02d\n",h,m,s);
}
/**/
void solve()
{
    int i,j;
    int dau,cuoi;
    sapxep();
    khoitao();
    
    for(i=0;i<dl;i++)
    {
        dau = a[i] - 5;
        cuoi = a[i] * 2;
        while(true)
        {
            for(j=dau;j<cuoi;j++)
                d[j] = 1;
            dau = cuoi + (a[i] - 5);
            if(dau > 18000)
                break;
            cuoi = dau + a[i] + 5;
        }
    }
    
    for(i=0;i<=18000;i++)
        if(d[i] == 0)
            break;
    if(i > 18000)
        printf("Signals fail to synchronise in 5 hours\n");
    else
        output(i);
}
/**/
void input()
{
    while(true)
    {
        scanf("%d",&a[0]);
        if(!a[0])
            break;
        dl = 1;
        while(true)
        {
            scanf("%d",&a[dl]);
            if(!a[dl])
                break;
            dl++;
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
