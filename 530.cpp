/*
                                                        Hoang Linh
                                                        
                                            Problem: BINOMIAL SHOWDOWN - 530 (530.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "530.inp"
#define fo "530.out"
/**/
using namespace std;
/**/
int a[40000],b[40000];
int mingt,maxgt,n,k;
/**/
void solve()
{
    int i,j;
    int maxa,maxb;
    long up,down;
    
    for(i=0,j=mingt;j>1;j--,i++)
        a[i] = j;
    maxa = i;
    for(j=0,i=maxgt+1;i<=n;i++,j++)
        b[j] = i;
    maxb = j;
    
    for(i=0;i<maxb;i++)
    {
        for(j=0;j<maxa;j++)
        {
            if(b[i] % a[j] == 0 && a[j] != 1)    
            {
                b[i] = b[i] / a[j];
                a[j] = 1;
            }
        }
    }
    up = down = 1;
    for(i=0;i<maxb;i++)
        up = up * b[i];
    for(j=0;j<maxa;j++)
        if(a[j] != 1)
            down = down * a[j];
            
    up = up / down;
    printf("%ld\n",up);
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d",&n,&k);
        if(!n && !k)
            break;
        if(n-k > k)
        {
            maxgt = n-k;
            mingt = k;
        }
        else
        {
            maxgt = k;
            mingt = n - k;
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
