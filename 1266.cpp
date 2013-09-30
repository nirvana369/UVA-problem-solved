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

#define fi "1266.inp"
#define fo "1266.out"
/**/
using namespace std;
/**/
int a[16][16],tong[16];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = 0;
}
/**/
void output()
{
    int i,j;
    int temp;
    temp = n * n;
    printf("n=%d, sum=%d\n",n,tong[n]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp < 10)
                printf("%2d",a[i][j]);
            else if(temp < 100)
                printf("%3d",a[i][j]);
            else
                printf("%4d",a[i][j]);
        }
        printf("\n");
    }
}
/**/
void solve()
{
    int x,y,px,py;
    int id;
    khoitao();
    x = 1;
    y = (n+1)/2;
    a[x][y] = 1;
    id = 2;
    while(id <= n*n)
    {
        px = x - 1;
        py = y + 1;
        if(px < 1)
            px = n;
        if(py > n)
            py = 1;
        if(a[px][py] == 0)
            a[px][py] = id++;
        else
        {
            px = x + 1;
            py = y;
            a[px][py] = id++;
        }
        x = px;
        y = py;
    }
    output();
}
/**/
void precal()
{
    int i,j;
    int temp;
    for(i=3;i<=15;i+=2)
        tong[i] = i*i;
    i = 3;
    temp = 0;
    for(j=1;j<=15*15;j++)
    {
        temp += j;
        if(j == tong[i])
        {
            tong[i] = temp / i;
            i += 2;
        }
    }
}
/**/
void input()
{
    int ntest;
    precal();
    ntest = 0;
    while(scanf("%d",&n) == 1)
    {
        if(ntest++)
            printf("\n");
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
