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

#define fi "796.inp"
#define fo "796.out"
/**/
using namespace std;
/**/
struct cau{
                int nut1,nut2;
            };
cau br[1100];
int a[1100][1100],d[1100],q[1100];
int db,n;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
void loang(int s,int e)
{
    int dau,cuoi;
    int i;
    bool coduong;
    
    coduong = false;
    dau = -1;
    cuoi = 0;
    d[s] = 1;
    q[0] = s;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<n;i++)
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
                if(i == e)
                {
                    coduong = true;
                    break;
                }
            }
        if(coduong)
            break;
    }
    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
    
    if(!coduong)
    {
        br[db].nut1 = s;
        br[db].nut2 = e;
        db++;
    }
}
/**/
void solve()
{
    int i,j;
    
    db = 0;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i][j] == 1 && a[j][i] == 1)
            {
                a[i][j] = a[j][i] = 0;
                loang(i,j);
                a[i][j] = a[j][i] = 1;
            }
            
    printf("%d critical links\n",db);
    for(i=0;i<db;i++)
        printf("%d - %d\n",br[i].nut1,br[i].nut2);
    printf("\n");
}
/**/
void input()
{
    int i,j;
//    char s[100];
    int m,dau,cuoi;
    
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%d (%d)",&dau,&m);
            //sscanf(s,"(%d)",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&cuoi);
                a[dau][cuoi] = 1;
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
