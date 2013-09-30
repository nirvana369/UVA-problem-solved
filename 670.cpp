/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "670.inp"
#define fo "670.out"
#define n 110
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado l[n],r[n];
int trai[n],phai[n],q[n],trc[n];
bool a[n][n],d[n];
int ntrai,nphai,last;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=ntrai;i++)
        for(j=1;j<=nphai;j++)
            a[i][j] = false;
}
/**/
double kc(toado u,toado v)
{
    return sqrt((u.x-v.x) * (u.x-v.x) + (u.y-v.y) * (u.y-v.y));
}
/**/
void loang(int xp)
{
    int i;
    int dau,cuoi;
    
    for(i=1;i<=nphai;i++)
        d[i] = true;
    dau = -1;
    cuoi = 0;
    q[cuoi] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nphai;i++)
            if(a[q[dau]][i] && d[i])
            {
                d[i] = false;
                trc[i] = q[dau];
                
                if(phai[i] == 0)
                {
                    last = i;
                    return;
                }
                cuoi++;
                q[cuoi] = phai[i];
            }
    }
}
/**/
void suanhan(int xp)
{
    int i,j;
    i = 0;
    while(i != xp)
    {
        i = trc[last];
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
        loang(i);
        if(last)
        {
            dem++;
            suanhan(i);
        }
    }
    printf("%d\n",ntrai+dem);
    for(i=1;i<=ntrai;i++)
    {
        if((i-1))
            printf(" ");
        printf("%d %d",l[i].x,l[i].y);
        if(trai[i] != 0)
            printf(" %d %d",r[trai[i]].x,r[trai[i]].y);
    }
    printf("\n");
}
/**/
void input()
{
    int i,j;
    double len,len1,len2;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&ntrai,&nphai);
        khoitao();
        for(i=1;i<=ntrai;i++)
        {
            scanf("%d %d",&l[i].x,&l[i].y);
            trai[i] = 0;
        }
        for(i=1;i<=nphai;i++)
        {
            scanf("%d %d",&r[i].x,&r[i].y);
            phai[i] = 0;
        }
        for(i=1;i<ntrai;i++)
        {
            len = 2*kc(l[i],l[i+1]);
            for(j=1;j<=nphai;j++)
            {
                len1 = kc(l[i],r[j]);
                len2 = kc(l[i+1],r[j]);
            
                if(len1 + len2 <= len)
                    a[i][j] = true;
            }
        }
        solve();
        if(ntest)
            printf("\n");
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
