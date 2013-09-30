/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "469.inp"
#define fo "469.out"
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
toado q[10010];
int d[110][110];
char a[110][110];
int n,m;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            d[i][j] = 0;
}
/**/
void loang(int hang,int cot)
{
    int i;
    int dau,cuoi;
    int water;
    toado p;
    
    q[0].x = hang;
    q[0].y = cot;
    dau = -1;
    cuoi = 0;
    d[hang][cot] = 1;
    if(a[hang][cot] == 'W')
        water = 1;
    else
        water = 0;
        
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<8;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.x < n && p.y >= 0 && p.y < m)
                if(a[p.x][p.y] == 'W' && d[p.x][p.y] == 0)
                {
                    cuoi++;
                    q[cuoi] = p;
                    d[p.x][p.y] = 1;
                    water++;
                }
        }
    }
    for(i=0;i<=cuoi;i++)
        d[q[i].x][q[i].y] = 0;
    printf("%d\n",water);
}
/**/
void input()
{
    int i;
    int hang,cot;
    int ntest;
    scanf("%d",&ntest);
    gets(a[0]);
    gets(a[0]);
    while(ntest--)
    {
        i = 0;
        while(true)
        {
            gets(a[i]);
            if(a[i][0] != 'L' && a[i][0] != 'W')
                break;
            i++;
        }
        n = i;
        m = strlen(a[i-1]);
        khoitao();
        while(true)
        {
            sscanf(a[i],"%d %d",&hang,&cot);
            hang--;
            cot--;
            loang(hang,cot);
            a[i][0] = 0;
            gets(a[i]);
            if(a[i][0] == 0)
                break;
        }
        if(ntest != 0)
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
