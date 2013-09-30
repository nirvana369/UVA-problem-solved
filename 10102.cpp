/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10102.inp"
#define fo "10102.out"
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
toado q[10100];
char a[110][110];
bool d[110][110];
int kc[10100];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
            d[i][j] = d[j][i] = true;
}
/**/
int loang(int r,int c)
{
    int i;
    int dau,cuoi;
    toado p;
    
    dau = -1;
    cuoi = 0;
    kc[0] = 0;
    d[r][c] = false;
    q[0].x = r;
    q[0].y = c;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.x < n && p.y >= 0 && p.y < n)
                if(d[p.x][p.y])
                {
                    cuoi++;
                    d[p.x][p.y] = false;
                    q[cuoi] = p;
                    kc[cuoi] = kc[dau] + 1;
                    
                    if(a[p.x][p.y] == '3')
                    {
                        for(i=0;i<=cuoi;i++)
                            d[q[i].x][q[i].y] = true;
                        return kc[cuoi];
                    }
                }
        }
    }
}
/**/
void solve()
{
    int i,j;
    int dist,tmp;
    
    dist = 0;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j] == '1')
            {
                tmp = loang(i,j);
                if(tmp > dist)
                    dist = tmp;
            }
    printf("%d\n",dist);
}
/**/
void input()
{
    int i;
    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<n;i++)
            scanf("%s",&a[i]);
        khoitao();
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
