/*
                                                    Hoang Linh
                                                    
                                            Problem: NETWORK - 315 (315.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "315.inp"
#define fo "315.out"
/**/
using namespace std;
/**/
int a[110][110],d[110],q[110];
int n;
/**/
void loang(int id)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    
    q[0] = id;
    d[id] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
            }
    }
}
/**/
void resetd(int id)
{
    int i;
    for(i=1;i<=n;i++)
        d[i] = 0;
    d[id] = 1;
}
/**/
void solve()
{
    int i,j;
    int vung,dvung;
    int kq;
    
    vung = 0;
    
    for(i=1;i<=n;i++)
        if(d[i] == 0)
        {
            loang(i);
            vung++;
        }
    kq = 0;
    for(i=1;i<=n;i++)
    {
        resetd(i);
        dvung = 0;
        for(j=1;j<=n;j++)
            if(d[j] == 0)
            {
                loang(j);
                dvung++;
            }
        if(dvung != vung)
            kq++;
    }
    printf("%d\n",kq);
}
/**/
bool xuly(char s[])
{
    int i;
    char temp[1000];
    int l,x,y,dem;
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    i = 0;
    while(i <= l)        
    {
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&x);
            dem = 0;
            break;
        }
        else if(s[i] != ' ')
        {
            temp[dem] = s[i];
            dem++;
        }
        i++;
    }
    
    if(x == 0)
    {
        solve();
        return true;
    }
    
    while(i <= l)
    {
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&y);
            a[x][y] = 1;
            a[y][x] = 1;            
            dem = 0;
        }
        else if(s[i] != ' ')
        {
            temp[dem] = s[i];
            dem++;
        }
        i++;
    }
    return false;
}
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        khoitao();
        gets(temp);
        while(true)
        {
            gets(temp);
            if(xuly(temp))
                break;
        }
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
