/*
                                            Hoang Linh
                                        
                                    Problem: COMBINATIONS - 369 (369.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "369.inp"
#define fo "369.out"
/**/
using namespace std;
/**/
int a[110],b[110];
int n,m,maxa,maxb,maxgt,mingt;
/**/
int ucln(int x,int y)
{
    int r;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
/**/
void solve()
{
    int i,j;
    long long gta,gtb;
    int temp;
    maxa = 0;
    for(i=maxgt+1;i<=n;i++,maxa++)
        a[maxa] = i;
    maxb = 0;
    for(i=2;i<=mingt;i++,maxb++)
        b[maxb] = i;
    
    for(i=0;i<maxa;i++)
        for(j=0;j<maxb;j++)
            if(b[j] != 1)
            {
                temp = ucln(a[i],b[j]);
                if(temp != 1)                
                {
                    a[i] = a[i] / temp;
                    b[j] = b[j] / temp;
                }
            }
    gta = 1;
    gtb = 1;
    i = 0;
    while(i < maxa || i < maxb)
    {
        if(i < maxa)
            gta *= a[i];
        if(i < maxb)
            gtb *= b[i];
        i++;
    }
    gta /= gtb;
    printf("%d things taken %d at a time is %lld exactly.\n",n,m,gta);
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)
            break;
        if(n-m > m)
        {
            maxgt = n-m;
            mingt = m;
        }
        else
        {
            maxgt = m;
            mingt = n-m;
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
