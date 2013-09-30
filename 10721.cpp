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

#define fi "10721.inp"
#define fo "10721.out"
#define n 51
/**/
using namespace std;
/**/
unsigned long long int bar[n+5][n+5][3];
int m,nb;
/**/
void _init()
{
    int i,j,k;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<2;k++)
                    bar[i][j][k] = 0;
}
/**/
unsigned long long int dfs(int nbar,int maxbar,int wid)
{
    int i;
    unsigned long long int sum;
    
    if(!nbar && !maxbar)
    {
        bar[nbar][maxbar][wid] = 1;
        return 1;
    }

    if(!nbar || !maxbar)
    {
        bar[nbar][maxbar][wid] = 0;
        return 0;
    }

    if(bar[nbar][maxbar][wid])
        return bar[nbar][maxbar][wid];
        
    sum = 0;
    for(i=1;i<=nbar&&i<=m;i++)
        sum += dfs(nbar-i,maxbar-1,wid^1);
        
    bar[nbar][maxbar][wid] = sum;
    return bar[nbar][maxbar][wid];
}
/**/
void input()
{
    int k;
    
    while(scanf("%d %d %d",&nb,&k,&m) == 3)
    {
        _init();
        dfs(nb,k,1);
        printf("%llu\n",bar[nb][k][1]);
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
