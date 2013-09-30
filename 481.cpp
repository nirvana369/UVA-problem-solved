/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "481.inp"
#define fo "481.out"
#define m 1000000
/**/
using namespace std;
/**/
long long a[m+10],kq[m+10],d[m+10],trc[m+10];
/**/
void input()
{
    long i,j;
    long maxlen,vt;
    
    i = 0;
    while(scanf("%lld",&a[i]) == 1)
    {
        d[i] = 0;
        len[i] = 0;
        i++;
    }
    
    n = i - 1;    
    d[i] = n; 
    len[1] = n;
    m = 1;
    n--;
    while(n >= 0)    
    {
        if(len[n] < m && a[n] < a[len[m]])
        {
            m = m + 1;
        }
    }
    
    printf("%ld\n-\n",j+1);
    for(i=j;i>=0;i--)
        printf("%lld\n",kq[i]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
