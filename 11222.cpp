/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11222.inp"
#define fo "11222.out"
/**/
using namespace std;
/**/
bool f[4][10010];
int luu[4][10010];
int d[4];
/**/
void khoitao()
{
    int j;
    
    for(j=1;j<=3;j++)
        d[j] = 0;
        
    for(j=0;j<10001;j++)
        f[1][j] = f[2][j] = f[3][j] = false;
    
}
/**/
bool chk(int i,int j)
{
    if(i == 1)
    {
        if(!f[2][j] && !f[3][j])
            return true;
        return false;
    }
    if(i == 2)
    {
        if(!f[1][j] && !f[3][j])
            return true;
        return false;
    }
    
    if(!f[1][j] && !f[2][j])
        return true;
    return false;
}
/**/
void sapxep(int id)
{
    int i,j;
    int tmp;
    
    for(i=0;i<d[id];i++)
        for(j=i+1;j<d[id];j++)
            if(luu[id][i] > luu[id][j])
            {
                tmp = luu[id][j];
                luu[id][j] = luu[id][i];
                luu[id][i] = tmp;
            }
}
/**/
void output(int id)
{
    int i;
    printf("%d %d",id,d[id]);
    for(i=0;i<d[id];i++)
        printf(" %d",luu[id][i]);
    printf("\n");
}
/**/
void solve()
{
    int i,j;
    int maxp;
    
    maxp = 0;
    for(i=1;i<=3;i++)
    {
        for(j=0;j<10001;j++)
            if(f[i][j] && chk(i,j))
                luu[i][d[i]++] = j;

        if(d[i] > maxp)
            maxp = d[i];
    }
    
    for(i=1;i<=3;i++)
        if(d[i] == maxp)
        {
            sapxep(i);
            output(i);
        }
}
/**/
void input()
{
    int i,j;
    int np,p;
    int ntest,id;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        khoitao();
        for(i=1;i<4;i++)
        {
            scanf("%d",&np);
            for(j=0;j<np;j++)
            {
                scanf("%d",&p);
                f[i][p] = true;
            }
        }
        printf("Case #%d:\n",id++);
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
