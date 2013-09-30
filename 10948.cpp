/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10948.inp"
#define fo "10948.out"
/**/
using namespace std;
/**/
int d[1000010];
long vt[1000010],nt[1000010];
long dnt;
/**/
void precal()
{
    long i,j;
    
    for(i=2;i<=1000000;i++)
    {
        d[i] = 0;
        vt[i] = i;
    }
    dnt = 0;
    for(i=2;i<=1000000;i++)
    {
        if(d[i] == 0)
        {
            vt[i] = dnt;
            nt[dnt++] = i;
            if(i <= 1000)
                for(j=i*i;j<=1000000;j+=i)
                    d[j] = 1;
        }
        else
            vt[i] = dnt;
    }
}
/**/
void input()
{
    long i;
    long n;
    precal();
    while(true)
    {
        scanf("%ld",&n);
        if(!n)
            break;
        printf("%ld:\n",n);
        for(i=vt[n];i>=0;i--)
            if(n-nt[i] > 1 && d[n-nt[i]] == 0)
            {
                printf("%ld+%ld\n",n-nt[i],nt[i]);
                break;
            }
        if(i < 0)
            printf("NO WAY!\n");
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
