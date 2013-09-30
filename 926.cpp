/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "926.inp"
#define fo "926.out"
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
                
long long d[35][35];
bool a[35][35][35][35];
int n;
toado xp,kt;
/**/
void khoitao()
{
    int i,j,k;
    int x,y;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            for(k=0;k<4;k++)
            {
                x = i + h[k].x;
                y = j + h[k].y;
                if(x >= 1 && x <= n && y >= 1 && y <= n)
                    a[i][j][x][y] = true;
            }
            d[i][j] = 0;
        }
}
/**/
int getdir(char huong)
{
    if(huong == 'N')
        return 1;
    if(huong == 'E')
        return 2;
    if(huong == 'S')
        return 3;
    return 0;
}
/**/
long long solve(int hang, int cot)
{
    int i;

    if(hang == kt.x && cot == kt.y)
        return 1;
    
    if(d[hang][cot])
        return d[hang][cot];
    
    if(hang + 1 <= n)
        if(a[hang][cot][hang+1][cot])
        {
            a[hang][cot][hang+1][cot] = false;
            d[hang][cot] += solve(hang+1,cot);
        }
        
    if(cot + 1 <= n)
        if(a[hang][cot][hang][cot+1])
        {
            a[hang][cot][hang][cot+1] = false;
            d[hang][cot] += solve(hang,cot+1);
        }
                
    return d[hang][cot];
}
/**/
void out()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%lld ",d[i][j]);
        printf("\n");
    }
}
/**/
void input()
{
    int i;
    int ntest;
    char s[5];
    int x,y,x1,y1;
    long long kq;
    int m,dir;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        khoitao();
        scanf("%d %d %d %d",&xp.x,&xp.y,&kt.x,&kt.y);
        
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %s",&x,&y,&s);
            dir = getdir(s[0]);
            x1 = x + h[dir].x;
            y1 = y + h[dir].y;
            a[x][y][x1][y1] = a[x1][y1][x][y] = false;            
        }
        kq = solve(xp.x,xp.y);
        printf("%lld\n",kq);
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
