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
#include <vector>

#define fi "232.inp"
#define fo "232.out"
/**/
using namespace std;
/**/
char a[1000][1000];
int d[1000][1000],cs[1000][1000];
int nhang,ncot,id;
/**/
void xuly(int hang,char s[])
{
    int i;
    int dem,tg;
    char temp[1000];
    
    i = dem = 0;
    while(s[i])
    {
        d[hang][i] = 0;
        if(s[i] == '*')
        {
            if(dem != 0)
            {
                temp[dem] = 0;
                printf("%3d.%s\n",tg,temp);
            }
            dem = 0;
        }
        else
        {
            if(!dem)
                tg = id;
            temp[dem++] = s[i];
            if((!hang || !i || a[hang-1][i]=='*' || a[hang][i-1]=='*'))
                cs[hang][i] = id++;
        }
        i++;
    }
    
    if(dem != 0)
    {
        temp[dem] = 0;
        printf("%3d.%s\n",tg,temp);
    }
}
/**/
void solve()
{
    int i,j,k;
    
    printf("Down\n");

    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(a[i][j] != '*' && !d[i][j])
            {
                printf("%3d.",cs[i][j]);
                for(k=i;k<nhang;k++)
                    if(a[k][j] == '*')
                        break;
                    else
                    {
                        printf("%c",a[k][j]);
                        d[k][j] = 1;
                    }
                printf("\n");
            }
}
/**/
void input()
{
    int i;
    int idx;
    idx = 0;
    while(scanf("%d",&nhang))
    {
        if(!nhang)
            break;
        scanf("%d",&ncot);
        id = 1;
        if(idx)
            printf("\n");
        printf("puzzle #%d:\nAcross\n",++idx);
        for(i=0;i<nhang;i++)
        {
            scanf("%s",&a[i]);
            xuly(i,a[i]);
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
