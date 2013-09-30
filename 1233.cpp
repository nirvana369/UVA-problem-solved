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

#define fi "1233.inp"
#define fo "1233.out"
/**/
using namespace std;
/**/
long a[510][510],nhan[510];
int np,n;
long maxcoin;
int p[510];
/**

/**/
void solve()
{
    int i,j,k;
    long box,mincoin,ans;
    
    for(k=0;k<=n;k++)
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    
    mincoin = maxcoin;
    
    for(i=0;i<np;i++)
        mincoin = min(mincoin,a[p[i]][0]);
    
    ans = 0;
    box = 0;
    
    while(box + mincoin < maxcoin)
    {
        ans++;
        box += mincoin;
        box--;
    }
    printf("%ld\n",ans);
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            a[i][j] = maxcoin;
        nhan[i] = maxcoin;
    }
}
/**/
void input()
{
    int i,j;
    long gt;
    int ntest;
    int m,x;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %d",&maxcoin,&n);
        scanf("%d",&np);
        
        for(i=0;i<np;i++)
            scanf("%d",&p[i]);
            
        khoitao();
        
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%ld %d",&gt,&x);
                a[i][x] = gt< a[i][x] ? gt : a[i][x];
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
