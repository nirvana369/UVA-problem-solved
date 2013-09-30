/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10349.inp"
#define fo "10349.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0, 
                0,1,
                1,0,
                0,-1};
int vt[500][500],phai[500],trai[500],q[500],trc[500];
bool a[500][500],d[500];
char tab[50][50];
int n,last,nhang,ncot,ntrai,nphai;
/**/
void noi()
{
    int i,j,k;
    int nut,x,y,nut1;
    
    for(i=1;i<=ntrai;i++)
    {
        for(j=1;j<=nphai;j++)
            a[i][j] = false;
        trai[i] = 0;
    }
    for(j=1;j<=nphai;j++)
        phai[j] = 0;
        
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(tab[i][j] == '*')
            {
                nut = vt[i][j];
                if(!((i + j) % 2))
                {
                    for(k=0;k<4;k++)
                    {
                        x = i + h[k].x;
                        y = j + h[k].y;
                        if(x >= 0 && x < nhang && y >= 0 && y < ncot)
                            if(tab[x][y] == '*' && (x + y) % 2)
                            {
                                nut1 = vt[x][y];
                                a[nut][nut1] = true;
                            }
                    }
                }
            }
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
    q[0] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nphai;i++)
            if(d[i] && a[q[dau]][i])
            {
                d[i] = false;
                trc[i] = q[dau];
                if(!phai[i])
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
void gannhan(int xp)
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
            gannhan(i);
        }
    }
    printf("%d\n",n-dem);
}
/**/
void input()
{
    int i,j;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&nhang,&ncot);
        n = 0;
        ntrai = nphai = 0;
        for(i=0;i<nhang;i++)
        {
            scanf("%s",&tab[i]);
            for(j=0;j<ncot;j++)
                if(tab[i][j] == '*') 
                {
                    n++;
                    if((i+j) % 2)
                        vt[i][j] = ++nphai;
                    else
                        vt[i][j] = ++ntrai;
                }
        }
        noi();
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
