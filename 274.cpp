/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "274.inp"
#define fo "274.out"
/**/
using namespace std;
/**/
int cat[110][110],mouse[110][110],dc[110],dm[110],q[110];
int nroom,rcat,rmouse;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=nroom;i++)
    {
        for(j=1;j<=nroom;j++)
        {
            cat[i][j] = 0;
            mouse[i][j] = 0;
        }
        dc[i] = 0;
        dm[i] = 0;
    }
}
/**/
void loangcat()
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = rcat;
    dc[rcat] = 1;
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nroom;i++)
            if(dc[i] == 0 && cat[q[dau]][i] == 1)
            {
                cuoi++;
                q[cuoi] = i;
                dc[i] = 1;
            }
    }
}
/**/
bool loangmouse(int flag)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0] = rmouse;
    if(dc[rmouse] == 1 && flag == 1)
        return false;
        
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nroom;i++)
            if(dm[i] == 0 && mouse[q[dau]][i] == 1)
            {
                cuoi++;
                q[cuoi] = i;
                if(dc[i] == 1)
                    dm[i] = 2;
                else
                    dm[i] = 1;
                if(flag == 1 && i == rmouse)
                    return true;
            }
    }
    return false;
}
/**/
void solve()
{
    int i;
    bool gap,coduong;

    gap = false;
    loangcat();
    loangmouse(0);
    if(dc[rmouse] == 1)
        dm[rmouse] = 2;
    for(i=1;i<=nroom;i++)
    {
        if(dm[i] == 2)
            gap = true;
        else if(dc[i] == 0)
            dm[i] = 0;
    }
    coduong = loangmouse(1);

    if(gap)
        printf("Y ");
    else
        printf("N ");
    
    if(coduong)
        printf("Y");
    else
        printf("N");
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    int x,y;
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        sscanf(temp,"%d %d %d",&nroom,&rcat,&rmouse);
        khoitao();
        while(true)
        {
            scanf("%d %d",&x,&y);
            if(x < 0 && y < 0)
                break;
            cat[x][y] = 1;
        }
        gets(temp);
        while(true)
        {
            temp[0] = 0;
            gets(temp);
            if(temp[0] == 0)
                break;
            sscanf(temp,"%d %d",&x,&y);
            mouse[x][y] = 1;
        }
        solve();
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
