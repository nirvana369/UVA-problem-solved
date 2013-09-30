/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "639.inp"
#define fo "639.out"
/**/
using namespace std;
/**/
char a[5][5];
int d[5][5];
int rooks,n;
/**/
void xuly(int hang,char s[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i] == 'X')
            d[hang][i] = 2;
        else
            d[hang][i] = 0;
    }
}
/**/
void copya(int s1[5][5],int s2[5][5])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s1[i][j] = s2[i][j];
}
/**/
bool kiemtra(int hang,int cot)
{
    int i;
    i = hang-1;
    while(i >= 0)
    {
        if(d[i][cot] == 1)
            return false;
        if(d[i][cot] == 2)
            break;
        d[i][cot] = 3;
        i--;
    }
    i = hang + 1;
    while(i < n)
    {
        if(d[i][cot] == 1)
            return false;
        if(d[i][cot] == 2)
            break;
        d[i][cot] = 3;
        i++;
    }
    i = cot - 1;
    while(i >= 0)
    {
        if(d[hang][i] == 1)
            return false;
        if(d[hang][i] == 2)
            break;
        d[hang][i] = 3;
        i--;
    }
    i = cot + 1;
    while(i < n)
    {
        if(d[hang][i] == 1)
            return false;
        if(d[hang][i] == 2)
            break;
        d[hang][i] = 3;
        i++;
    }
    return true;
}
/**/
void solve(int dat)
{
    int i,j;
    int temp[5][5];
    if(dat > rooks)
        rooks = dat;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(d[i][j] == 0)
            {
                copya(temp,d);
                if(kiemtra(i,j))
                {
                    d[i][j] = 1;
                    
                    solve(dat+1);
                }
                copya(d,temp);
            }
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        gets(a[0]);
        for(i=0;i<n;i++)
        {
            gets(a[i]);
            xuly(i,a[i]);
        }
        rooks = 0;
        solve(0);
        printf("%d\n",rooks);
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
