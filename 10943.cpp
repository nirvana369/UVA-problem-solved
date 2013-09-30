/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "10943.inp"
#define fo "10943.out"
#define m 1000000
/**/
using namespace std;
/**/
long a[105][105];
/**/
void _rs()
{
    int i,j;
    
    for(i=0;i<101;i++)
    {
        a[i][1] = 1;
        for(j=2;j<101;j++)
            a[i][j] = 0;
    }
}
/**/
long solve(int n,int k)
{
    long sum;
    int i;
    
    if(a[n][k])
        return a[n][k];
    
    sum = 0;
    for(i=0;i<=n;i++)
    {
        sum += solve(i,k-1);
        sum %= m;
    }
    
    a[n][k] = sum;
    return a[n][k];
}
/**/
void input()
{
    int n,k;
    long kq;
    
    _rs();
    while(scanf("%d %d",&n,&k))
    {
        if(!n && !k)
            break;
        kq = solve(n,k);
        printf("%ld\n",kq);
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
