/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "825.inp"
#define fo "825.out"
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
toado q[1000100];
bool a[1100][1100],d[1100][1100];
int kc[1100][1100];
int nhang,ncot,dem;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=nhang;i++)
        for(j=1;j<=ncot;j++)
        {
            a[i][j] = true;
            d[i][j] = true;
            kc[i][j] = 32000;
        }
}
/**/
void xuly(char s[])
{
    int i;
    int x,y;
    char tmp[100];
    
    i = dem = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            dem = 0;
            break;
        }
        i++;
    }
    sscanf(tmp,"%d",&x);
    dem = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            sscanf(tmp,"%d",&y);
            a[x][y] = false;
            dem = 0;
        }
        i++;
    }
    
    if(dem != 0)
    {
        tmp[dem] = 0;
        sscanf(tmp,"%d",&y);
        a[x][y] = false;
    }
}
/**/
void loang()
{
    int i;
    int dau,cuoi;
    toado p;
    
    dau = -1;
    cuoi = 0;
    q[0].x = 1;
    q[0].y = 1;
    d[1][1] = false;
    kc[1][1] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x == 4 && p.y == 4)
            {
                p.x = 4;
            }
            if(p.x > 0 && p.x <= nhang && p.y > 0 && p.y <= ncot)
                if(d[p.x][p.y] && a[p.x][p.y])
                {
                    cuoi++;
                    q[cuoi] = p;
                    d[p.x][p.y] = false;
                    kc[p.x][p.y] = kc[q[dau].x][q[dau].y] + 1;
                }
        }
    }
}
/**/
void dq(int hang,int cot,int step)
{
    int i;
    int x,y;
    
    if(step == kc[nhang][ncot])
    {
        if(hang == nhang && cot == ncot)
            dem++;
        return;
    }
    
    for(i=0;i<4;i++)
    {
        x = hang + h[i].x;
        y = cot + h[i].y;
        if(x > 0 && x <= nhang && y > 0 && y <= ncot)
            if(a[x][y] && step + 1 == kc[x][y])
                dq(x,y,step+1);
    }
}
/**/
void solve()
{
    loang();
    dem = 0;
    if(kc[nhang][ncot] != 32000)
        dq(1,1,0);
    printf("%d\n",dem);
}
/**/
void input()
{
    int i;
    char s[1000];
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&nhang,&ncot);
        gets(s);
        khoitao();
        for(i=0;i<nhang;i++)
        {
            gets(s);
            xuly(s);
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
