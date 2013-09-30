/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "145.inp"
#define fo "145.out"
/**/
using namespace std;
/**/
float gia[6][5];
int cost[4],clk[6];
int t,t1,t2,ma;
char hyp[100],kt[100];
/**/
void xuly(int id)
{
    int cuoc;
    int bac;
    
    if(t1 >= 480 && t1 < 1080)
        bac = 1;
    else if(t1 >= 1080 && t1 < 1320)
        bac = 2;
    else
        bac = 3;
        
    if(clk[id] - t1 <= t)
    {
        cuoc = clk[id] - t1;
        t1 = clk[id];
        if(t1 == 1440)
            t1 = 0;
        t = t - cuoc;
    }
    else
    {
        cuoc = t2 - t1;
        t = 0;
    }
    cost[bac] += cuoc;
}
/**/
void solve()
{
    int i;
    double tong;
    for(i=1;i<4;i++)
        cost[i] = 0;
    i = 0;
    while(t != 0)
    {
        if(t1 < clk[i])
            xuly(i);
        i++;
        if(i == 5)
            i = 0;
    }
    tong = 0;
    for(i=1;i<4;i++)
        tong += gia[ma][i] * cost[i];
    printf("%10s %5d %5d %5d %2s %7.2lf\n",hyp,cost[1],cost[2],cost[3],kt,tong);
}
/**/
void khoitao()
{
    clk[0] = 0;
    clk[1] = 480;
    clk[2] = 1080;
    clk[3] = 1320;
    clk[4] = 1440;
    gia[1][1] = 0.10;
    gia[1][2] = 0.06;
    gia[1][3] = 0.02;
    
    gia[2][1] = 0.25;
    gia[2][2] = 0.15;
    gia[2][3] = 0.05;
    
    gia[3][1] = 0.53;
    gia[3][2] = 0.33;
    gia[3][3] = 0.13;
    
    gia[4][1] = 0.87;
    gia[4][2] = 0.47;
    gia[4][3] = 0.17;
    
    gia[5][1] = 1.44;
    gia[5][2] = 0.80;
    gia[5][3] = 0.30;
}
/**/
void input()
{
    char temp[10000];
    int h1,m1,h2,m2;
    khoitao();
    while(true)
    {
        gets(temp);
        if(temp[0] == '#')
            break;
        sscanf(temp,"%s %s %d %d %d %d",&kt,&hyp,&h1,&m1,&h2,&m2);
        t1 = h1 * 60 + m1;
        t2 = h2 * 60 + m2;
        t = t2 - t1;
        ma = kt[0] - 64;
        if(t <= 0)
            t = t + 1440;
        
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
