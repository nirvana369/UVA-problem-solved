/*
                                                    Hoang Linh
                                                    
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11159.inp"
#define fo "11159.out"
/**/
using namespace std;
/**/
int train[110],phaim[110],d[110],q[110],truoc[110],noi[110][110];
long long a[110],b[110];
int n,m;
int idcuoi;
int zero;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            noi[i][j] = 0;
}
/**/
bool loang(int xp)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    
    for(i=1;i<=n;i++)
        d[i] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(noi[q[dau]][i] == 1 && d[i] == 0)
            {
                if(train[i] == 0)
                {
                    truoc[i] = q[dau];
                    idcuoi = i;
                    return true;
                }
                cuoi++;
                q[cuoi] = train[i];
                truoc[i] = q[dau];
                d[i] = 1;
            }
    }
    return false;
}
/**/
void tomau(int xp)
{
    int i,j,temp;
    j = idcuoi;
    do
    {
        i = truoc[j];
        temp = phaim[i];
        phaim[i] = j;
        train[j] = i;
        j = temp;
    }while(i != xp);
}
/**/
void solve()
{
    int i;
    bool find;
    int kq;
    
    kq = 0;
    
    for(i=1;i<=m;i++)
    {
        find = loang(i);
        if(find)
        {
            kq++;
            tomau(i);
        }
    }
    printf("%d\n",kq);
}
/**/
void input()
{
    int itest,i,j;
    int ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d",&n);
        
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            train[i] = 0;
        }
        scanf("%d",&m);
        khoitao();
        for(i=1;i<=m;i++)
        {
            scanf("%lld",&b[i]);
            phaim[i] = 0;
            for(j=1;j<=n;j++)
                if(a[j] != 0)
                {
                    if(b[i] % a[j] == 0)
                        noi[i][j] = 1;
                }
                else if(b[i] == 0)            
                    noi[i][j] = 1;
        }
        printf("Case %d: ",itest+1);
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
