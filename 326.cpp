/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "326.inp"
#define fo "326.out"
/**/
using namespace std;
/**/
long a[12][12];
int n,k;
/**/
void solve()
{
    int i,j;
    int c;
    
    c = n;   
    for(i=1;i<=n;i++)
    {
        for(j=n-i;j>=1;j--)
            a[j][i+1] = a[j+1][i] - a[j][i];
    }
    
    a[1][c+1] = 0;
    for(i=2;i<=n+k;i++)
    {
        for(j=1;j<=c;j++)
            a[2][j] = a[1][j] + a[1][j+1];

        for(j=1;j<=c+1;j++)
            a[1][j] = a[2][j];
    }
    printf("Term %d of the sequence is %ld\n",n+k,a[1][1]);
}
/**/
void input()
{
    int i;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
            scanf("%ld",&a[i][1]);
        scanf("%d",&k);
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
