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

#define fi "1247.inp"
#define fo "1247.out"
/**/
using namespace std;
/**/
int a[30][30],nhan[30],d[30],truoc[30];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<27;i++)
        for(j=0;j<27;j++)
            a[i][j] = -1;
}
/**/
void resetnhan()
{
    int i;
    for(i=0;i<27;i++)
    {
        d[i] = 0;
        nhan[i] = 10000;
    }
}
/**/
int timnhan()
{
   int vt,i;
   int val;
   
   vt = -1;
   val = 10000;
   for(i=0;i<27;i++) 
        if(d[i] == 0 && nhan[i] < val)
        {
            val = nhan[i];
            vt = i;
        }
    return vt;
}
/**/
void gannhan(int xp)
{
    int i;
    for(i=0;i<27;i++)
        if(a[xp][i] != -1 && nhan[xp] + a[xp][i] < nhan[i])
        {
            nhan[i] = nhan[xp] + a[xp][i];
            truoc[i] = xp;
        }
}
/**/
void solve(int xp,int kt)
{
    int io,i;
    int kq[30];
    
    resetnhan();
    nhan[xp] = 0;
    do
    {
        io = timnhan();
        if(io == kt || io == -1)
            break;
        d[io] = 1;
        gannhan(io);
    }while(true);
    
    i = 0;
    while(io != xp)
    {
        kq[i++] = io;
        io = truoc[io];
    }
    kq[i] = io;
    for(io=i;io>=0;io--)
        if(io)
            printf("%c ",kq[io]+65);
        else
            printf("%c",kq[io]+65);
    printf("\n");
}
/**/
void input()
{
    char s1[10],s2[10];
    int i;
    int p,gt;
    scanf("%d %d",&n,&p);
    khoitao();
    for(i=0;i<p;i++)
    {
        scanf("%s %s %d",&s1,&s2,&gt);
        a[s1[0]-65][s2[0]-65] = gt;
        a[s2[0]-65][s1[0]-65] = gt;
    }
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        scanf("%s %s",&s1,&s2);
        solve(s1[0]-65,s2[0]-65);
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
