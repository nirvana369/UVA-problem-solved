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

#define fi "10735.inp"
#define fo "10735.out"
/**/
using namespace std;
/**/
int a[110][110],d[110],dd[110];
int n,m;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 0;
        d[i] = 0;
        dd[i] = 0;
    }
    
}
/**/
void dq(int xp)
{
    int i;
    if(!m && a[xp][1] > 0)
    {
        printf(" 1\n");
        return;
    }
        
    for(i=1;i<=n;i++)
        if(a[xp][i] > 0)
        {
            a[xp][i]--;
            a[i][xp]--;
            if(!dd[i])
            {
                dd[i] = 1;
                m--;
            }
            printf(" %d",i);
            dq(i);
        }
}
/**/
void solve()
{
    int i;
    
    m = n-1;
    
    for(i=1;i<=n;i++)
        if((d[i] % 2))
        {
            printf("No euler circuit exist\n");
            return;
        }
    dd[1] = 1;
    printf("1");
    dq(1);
}
/**/
void input()
{
    char s[3];
    int x,y;
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %s",&x,&y,&s);
            
            if(s[0] == 'U')
            {
                d[x]++;
                d[y]++;
                a[x][y]++;
                a[y][x]++;
            }
            else
            {
                d[y]++;
                a[x][y]++;
            }
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
