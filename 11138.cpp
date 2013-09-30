/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11138.inp"
#define fo "11138.out"
/**/
using namespace std;
/**/
int ntrai,nphai,last;
int a[510][510],phai[510],trai[510],q[510],truoc[510],d[510];
/**/
void khoitao()
{
    int i;
    for(i=1;i<=ntrai;i++)
        trai[i] = 0;
    for(i=1;i<=nphai;i++)
        phai[i] = 0;
}
/**/
void timduong(int xp)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    
    for(i=1;i<=nphai;i++)
        d[i] = 0;
        
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nphai;i++)
            if(a[q[dau]][i] && !d[i])
            {
                d[i] = 1;
                truoc[i] = q[dau];
                if(!phai[i])
                {
                    last = i;
                    return;
                }
                else if(i != trai[q[dau]])
                {
                    cuoi++;
                    q[cuoi] = phai[i];
                }
            }
    }
}
/**/
void suaduong(int xp)
{
    int i,j;
    i = 0;
    while(i != xp)
    {
        i = truoc[last];
        j = trai[i];
        phai[last] = i;
        trai[i] = last;
        last = j;
    }
}
/**/
void solve()
{
    int i;
    int dem;
    
    dem = 0;
    for(i=1;i<=ntrai;i++)
    {
        last = 0;
        timduong(i);
        if(last != 0)
        {
            dem++;
            suaduong(i);
        }
    }
    printf("a maximum of %d nuts and bolts can be fitted together\n",dem);
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&ntrai,&nphai);
        for(i=1;i<=ntrai;i++)
            for(j=1;j<=nphai;j++)
                scanf("%d",&a[i][j]);
        khoitao();
        printf("Case %d: ",id++);
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
