/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10293.inp"
#define fo "10293.out"
/**/
using namespace std;
/**/
char s[110],tmp[50];
int d[40];
int dem;
/**/
void khoitao()
{
    int i;
    dem = 0;
    for(i=0;i<31;i++)
        d[i] = 0;
}
/**/
int chk()
{
    int i;
    int len;
    
    len = 0;
    for(i=0;i<dem;i++)
        if(tmp[i] >= 'a' && tmp[i] <= 'z' || tmp[i] >= 'A' && tmp[i] <= 'Z')
            len++;
    return len;
}
/**/
void solve()
{
    int i;
    i = 0;
    
    while(s[i])
    {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '-' || s[i] == 39)
            tmp[dem++] = s[i];
        else
        {
            if(dem != 0)
            {
                dem = chk();
                d[dem]++;
            }
            dem = 0;
        }
        i++;
    }
    
    if(dem != 0 && tmp[dem-1] != '-')
    {
        dem = chk();
        d[dem]++;
        dem = 0;
    }
}
/**/
void output()
{
    int i;
    for(i=1;i<31;i++)
        if(d[i] != 0)
            printf("%d %d\n",i,d[i]);
    printf("\n");
}
/**/
void input()
{
    khoitao();
    while(gets(s))
    {
        if(s[0] == '#')
        {
            output();
            khoitao();
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
