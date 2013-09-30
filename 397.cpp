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

#define fi "397.inp"
#define fo "397.out"
/**/
using namespace std;
/**/
int a[100];
int da,uutien;
char alpha[100];
/**/
int getsign(char kt)
{
    if(kt == '*')
        return 1;
    if(kt == '/')
        return 2;
    if(kt == '+')
        return 3;
    if(kt == '-')
        return 4;
}
/**/
void xuly(char s[])
{
    int i;
    int l,dem;
    char temp[1000];
    bool gapso;
    
    l = strlen(s);
    
    da = 0;
    dem = 0;
    uutien = 0;
    for(i=0;i<l;i++)
    {
        if(s[i] == '=')
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&a[da++]);
            i++;
            break;
        }
        if(s[i] != ' ')
        {
            if((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'))    
            {
                if(gapso)
                {
                    temp[dem] = 0;
                    sscanf(temp,"%d",&a[da++]);
                    a[da++] = getsign(s[i]);
                    if(a[da-1] == 1 || a[da-1] == 2)
                        uutien++;
                    gapso = false;
                    dem = 0;
                }
                else
                    temp[dem++] = s[i];
                    
            }
            else
            {
                temp[dem++] = s[i];
                gapso = true;
            }
        }
    }
    
    dem = 0;
    while(i < l)
    {
        if(s[i] != ' ')
            alpha[dem++] = s[i];
        i++;
    }
    alpha[dem] = 0;
}
/**/
char rsign(int val)
{
    if(val == 1)
        return '*';
    if(val == 2)
        return '/';
    if(val == 3)
        return '+';
    if(val == 4)
        return '-';
}
/**/
void process(int id1,int id2,int sign)
{
    int i,j;
    if(a[sign] == 1)
        a[id1] *= a[id2];
    if(a[sign] == 2)
        a[id1] /= a[id2];
    if(a[sign] == 3)
        a[id1] += a[id2];
    if(a[sign] == 4)
        a[id1] -= a[id2];
    for(i=sign,j=sign+2;j<da;j++,i++)
        a[i] = a[j];
    da -= 2;
}
/**/
void solve()
{
    int i;
    while(true)
    {
        for(i=0;i<da;i++)
        {
            if(i % 2 == 0)
                printf("%d ",a[i]);
            else
                printf("%c ",rsign(a[i]));
        }
        printf("= %s\n",alpha);
        if(da == 1)
            break;
        if(uutien)
        {
            for(i=1;i<da;i+=2)
                if(a[i] == 1 || a[i] == 2)
                {
                    process(i-1,i+1,i);
                    uutien--;
                    break;
                }
        }
        else
            process(0,2,1);
    }
}
/**/
void input()
{
    char temp[1000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        xuly(temp);
        solve();
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
