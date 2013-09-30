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

#define fi "11748.inp"
#define fo "11748.out"
/**/
using namespace std;
/**/
bool link[110][110],d[110];
int a[110][110],q[110];
int n,m,c;
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            link[i][j] = false;
        d[i] = true;
    }
}
/**/
int bfs(int x)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = x;
    d[x] = false;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(d[i] && link[q[dau]][i])
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = false;
            }
    }
    return cuoi + 1;
}
/**/
void solve()
{
    int i,j,k;
    int dem;
    
    khoitao();
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i != j)
            {
                dem = 0;
                for(k=1;k<=m;k++)
                    if(a[k][i] < a[k][j])
                        dem++;
                if(dem > m - dem)
                    link[i][j] = true;
            }
        }
        
            
    if(bfs(c) == n)
        printf("yes\n");
    else
        printf("no\n");
}
/**/
void input()
{
    int bp;
    int i,j;
    
    while(scanf("%d %d %d",&n,&m,&c))
    {
        if(!n && !m && !c)
            break;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&bp);
                a[i][bp] = j;
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
