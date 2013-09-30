/*
                                                    Hoang Linh
                                        
                                        Problem: SUPER LONG SUMS - 10013 (10013.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10013.inp"
#define fo "10013.out"
/**/
using namespace std;
/**/
int a[10000000];
long maxa,nlen;
/**/
void solve()
{
    long i;
    int l;
    char temp[100];
    
    for(i=maxa;i>0;i--)
    {
        a[i-1] = a[i-1] + a[i] / 10;
        a[i] = a[i] % 10;
    }
    sprintf(temp,"%d",a[1]);
    l = strlen(temp);
    if(l + maxa-1 == nlen)
        for(i=1;i<=maxa;i++)
            printf("%d",a[i]);
    else
    {
        for(i=1;i<=maxa;i++)
            printf("%d",a[i]);
        for(i=maxa+1;i<=nlen;i++)
            printf("0");
    }
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    int x,y;
    int itest;
    int ntest;
    scanf("%d",&ntest);
    
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%ld",&nlen);
        gets(temp);
        maxa = 0;
        while(true)
        {
            temp[0] = 0;
            gets(temp);
            if(temp[0] == 0)
                break;
            maxa++;
            sscanf(temp,"%d %d",&x,&y);
            a[maxa] = x + y;
        }
        solve();
        if(itest != ntest-1)
            printf("\n");
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
