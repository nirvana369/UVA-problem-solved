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

#define fi "208.inp"
#define fo "208.out"
/**/
using namespace std;
/**/
int a[25][25],d[25],kq[25],diem[25],q[25];
int n,maxr,droad,dp;
void khoitao()
{
    int i,j;
    for(i=1;i<22;i++)
    {
        for(j=1;j<22;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
    droad = 0;
    maxr = 0;
    dp = 0;
}
/**/
void dq(int id)
{
    int i;
    if(kq[id-1] == n)
    {
        for(i=0;i<id;i++)
        {
            if(i)
                printf(" ");
            printf("%d",kq[i]);
        }
        printf("\n");
        droad++;
        return;
    }
    for(i=1;i<dp;i++)
        if(a[kq[id-1]][diem[i]] == 1 && d[diem[i]] == 0)
        {
            d[diem[i]] = 1;
            kq[id] = diem[i];
            dq(id+1);
            d[diem[i]] = 0;
        }
}
/**/
void sapxep()
{
    int i,j;
    int temp;
    for(i=0;i<dp-1;i++)
        for(j=i+1;j<dp;j++)
            if(diem[i] > diem[j])
            {
                temp = diem[i];
                diem[i] = diem[j];
                diem[j] = temp;
            }
}
/**/
void loang()
{
    int dau,cuoi;
    int i;
    
    dau = -1;
    cuoi = 0;
    q[0] = n;
    d[n] = 0;
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=maxr;i++)
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                cuoi++;
                d[i] = 1;
                q[cuoi] = i;
                diem[dp++] = i;
            }
    }
    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
    sapxep();
}
/**/
void input()
{
    int x,y;
    int id;
    id = 1;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
            
        khoitao();
        while(true)
        {
            scanf("%d %d",&x,&y);
            if(!x && !y)
                break;
            a[x][y] = a[y][x] = 1;
            if(x > maxr)
                maxr = x;
            if(y > maxr)
                maxr = y;
        }
        loang();
        printf("CASE %d:\n",id++);
        kq[0] = 1;
        if(diem[0] == 1)
            dq(1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",droad,n);
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
