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
#include <vector>

#define fi "11838.inp"
#define fo "11838.out"
#define inf 30000
/**/
using namespace std;
/**/
int a[2010][2010];
int n;
/**/
void solve()
{
    int i,j,k;
    int flg;
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    flg = 1;    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(i != j && a[i][j] == inf)
            {
                flg = 0;
                break;
            }
            
        if(!flg)
            break;
    }
                
    cout << flg << endl;    
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = inf;
}
/**/
void input()
{
    long i,m;
    int x,y,z;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if((z-1))
                a[x][y] = a[y][x] = 0;
            else
                a[x][y] = 0;
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
