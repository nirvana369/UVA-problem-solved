/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "539.inp"
#define fo "539.out"
/**/
using namespace std;
/**/
int a[30][30];
int n,lenght;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j] = 0;
    }
    lenght = -1;
}
/**/
void getleng(int dau,int dodai)
{
    int i;
    if(dodai > lenght)
        lenght = dodai;

    for(i=0;i<n;i++)
    {
        if(a[dau][i] == 1)
        {
            a[dau][i] = 0;
            a[i][dau] = 0;
            
            getleng(i,dodai+1);
            
            a[dau][i] = 1;
            a[i][dau] = 1;
        }
    }
}
/**/
void input()
{
    int i;
    int m,x,y;
    while(true)
    {
        scanf("%d %d",&n,&m);
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
            a[y][x] = 1;
        }
        for(i=0;i<n;i++)
            getleng(i,0);
        printf("%d\n",lenght);
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
