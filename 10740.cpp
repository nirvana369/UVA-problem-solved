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

#define fi "10761.inp"
#define fo "10761.out"
/**/
using namespace std;
/**/
struct hangdoi{
                    int kc;
                    int dinh;
              };
hangdoi q[200000];
int a[110][110];
long long gt[110][110],kq[50];
int n,xp,kt,len,dkq;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        gt[i][0] = 0;

        for(j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = -1;
        a[i][i] = -1;
    }
    dkq = 1;
}
/**/
void solve()
{
    long dau,cuoi;
    int i;
    
    q[0].dinh = xp;
    q[0].kc = 0;
    dau = -1;
    cuoi = 0;
    
    while(dau != cuoi)
    {
        dau++;
        if(q[dau].kc <= 100)
            for(i=1;i<=n;i++)
                if(a[q[dau].dinh][i] != -1)
                {
                    cuoi++;
                    q[cuoi].dinh = i;
                    q[cuoi].kc = q[dau].kc + 1;

                    gt[i][q[cuoi].kc] = gt[q[dau].dinh][q[dau].kc] + a[q[dau].dinh][i];

                    if(i == kt)
                    {
                        kq[dkq++] = gt[i][q[cuoi].kc];
                        if(dkq > len)   
                            return;
                    }
                }
    }
}
/**/
void output()
{
    if(dkq <= len)
        printf("-1");
    else
        printf("%lld",kq[len]);
    printf("\n");
}
/**/
void input()
{
    int i;
    int n1,n2,val,m;
    
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        khoitao();
        scanf("%d %d %d",&xp,&kt,&len);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&n1,&n2,&val);
            a[n1][n2] = val;
        }
        solve();
        output();
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
