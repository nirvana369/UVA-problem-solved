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

#define fi "10596.inp"
#define fo "10596.out"
/**/
using namespace std;
/**/
int d[210],a[210][210],bac[210],q[210];
int n,nroad;
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            a[i][j] = 0;
        bac[i] = 0;
        d[i] = 0;
    }
}
/**/
void loang()
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[cuoi] = 0;
    d[0] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<n;i++)
            if(!d[i] && a[q[dau]][i])
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
            }
    }
}
/**/
bool solve()
{
    int i;
    
    for(i=0;i<n;i++)
        if(bac[i] % 2 != 0)
            return false;
    loang();
    for(i=0;i<n;i++)
        if(!d[i])
            return false;
    return true;
}
/**/
void input()
{
    int i;
    int x,y;
    while(scanf("%d %d",&n,&nroad) == 2)
    {
        khoitao();
        for(i=0;i<nroad;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
            bac[x]++;
            bac[y]++;
        }
        if(solve())
            printf("Possible\n");
        else
            printf("Not Possible\n");
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
