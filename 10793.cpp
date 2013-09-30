/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10793.inp"
#define fo "10793.out"
#define maxgt 1000000000l
/**/
using namespace std;
/**/
long long a[110][110];
int n,m;
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = maxgt;
}
/**/
void solve()
{
    int i,j,k;
    long long kq,maxr;
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    
        kq = -1;
        for(i=1;i<=n;i++)
        {
            maxr = -1;
            for(j=1;j<=n;j++) 
            {
                if(i != j)
                {
                    if(a[i][j] == maxgt)
                        break;
                    maxr = max(maxr, a[i][j]);
                }
            }
            if(j == n+1)
            {
                for(j=1;j<5;j++)
                    if(a[i][j] != a[i][j+1])
                        break;
                if(j==5 && (maxr < kq || kq == -1)) 
                    kq = maxr;
            }
        }
        printf("%lld\n", kq);
}
/**/
void input()
{
    int i;
    int x,y,val;
    int ntest,id;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&y,&x,&val);
            if(a[x][y] > val)
            {
                a[x][y] = val;
                a[y][x] = val;
            }
        }
        printf("Map %d: ",id++);
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
