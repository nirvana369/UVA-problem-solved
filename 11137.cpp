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

#define fi "11137.inp"
#define fo "11137.out"
/**/
using namespace std;
/**/
long long d[10010];
int coin[23];
/**/
void precal()
{
    int i,j;
    int temp;
    
    for(i=1;i<=10000;i++)
        d[i] = 0;
    d[0] = 1;
    for(i=1;i<22;i++)
        coin[i] = i*i*i;
        
    for(i=1;i<22;i++)
        for(j=0;j<=10000;j++)
        {
            temp = j + coin[i];
            if(temp <= 10000)
                d[temp] += d[j];
        }
}
/**/
void input()
{
    int n;
    precal();
    while(scanf("%d",&n) == 1)
        printf("%lld\n",d[n]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
