/*
                                                        Hoang Linh
                                                        
                                            Problem: OIL DEPOSITS - 572 (572.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "572.inp"
#define fo "572.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
toado q[11000];
int a[110][100],d[110][110];
int nhang,ncot;
/**/
void xuly(int hang,char s[])
{
    int i;
    for(i=0;i<ncot;i++)
    {
        d[hang][i] = 0;
        if(s[i] == '*')
            a[hang][i] = 0;
        else
            a[hang][i] = 1;
    }
}
/**/
void loang(int hang,int cot)
{
    int i;
    int dau,cuoi;
    toado p;
    
    dau = -1;
    cuoi = 0;
    
    d[hang][cot] = 1;
    q[0].x = hang;
    q[0].y = cot;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<8;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot)
                if(d[p.x][p.y] == 0 && a[p.x][p.y] == 1)
                {
                    cuoi++;
                    q[cuoi] = p;
                    d[p.x][p.y] = 1;
                }
        }
    }
}
/**/
void solve()
{
    int i,j;
    int dem;
    
    dem = 0;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(a[i][j] == 1 && d[i][j] == 0)
            {
                dem++;
                loang(i,j);
            }
    printf("%d\n",dem);
}
/**/
void input()
{
    int i;
    char temp[1000];
    while(true)
    {
        scanf("%d %d",&nhang,&ncot);
        if(!nhang && !ncot)
            break;
        gets(temp);
        for(i=0;i<nhang;i++)
        {
            gets(temp);
            xuly(i,temp);
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
