/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "260.inp"
#define fo "260.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[6] = {-1,-1,
                0,-1,
                1,0,
                -1,0,
                0,1,
                1,1};
toado q[40100];
char a[210][210];
int d[210][210];
int n;
/**/
bool loang(int hang,int cot)
{
    toado p;
    int dau,cuoi;
    int i;
    
    dau = -1;
    cuoi = 0;
    q[0].x = hang;
    q[0].y = cot;
    d[hang][cot] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<6;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.x < n && p.y >= 0 && p.y < n)
                if(a[p.x][p.y] == a[hang][cot] && d[p.x][p.y] == 0)
                {
                    cuoi++;
                    d[p.x][p.y] = 1;
                    q[cuoi] = p;
                    if(a[hang][cot] == 'w' && p.y == n-1)
                        return true;
                    if(a[hang][cot] == 'b' && p.x == n-1)
                        return true;
                }
        }
    }
    for(i=0;i<=cuoi;i++)
        d[q[i].x][q[i].y] = 0;
    return false;
}
/**/
void solve()
{
    int i;
    
    for(i=0;i<n;i++)
        if(a[i][0] == 'w')
            if(loang(i,0))
            {
                printf(" W\n");
                return;
            }
            
    for(i=0;i<n;i++)
        if(a[0][i] == 'b')
            if(loang(0,i))
            {
                printf(" B\n");
                return;
            }
}
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            d[i][j] = 0;
}
/**/
void input()
{
    int i,id;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        gets(a[0]);
        for(i=0;i<n;i++)
            gets(a[i]);
        khoitao();
        printf("%d",id);
        solve();
        id++;
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
