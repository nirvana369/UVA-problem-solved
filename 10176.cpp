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

#define fi "10176.inp"
#define fo "10176.out"
#define m 131071l
/**/
using namespace std;
/**/
char s[15000];
int base,ds;
/**/
long long laybac(int bac)
{
    int i;
    long long val;
    val = 1;
    for(i=0;i<bac;i++)
        val *= base;
    return val;
}
/**/
long long chuyenhe(char str[],int len)
{
    int i;
    long long val;
    val = 0;
    for(i=0;i<len;i++)
        val += (str[i] - 48) * laybac(len-i-1);
    return val;
}
/**/
void daochuoi(char str[],int dau,int cuoi)
{
    char temp;
    while(dau < cuoi)
    {
        temp = str[dau];
        str[dau] = str[cuoi];
        str[cuoi] = temp;
        dau++;
        cuoi--;
    }
}
/**/
int backbase(char str[],long long val)
{
    int i;
    i = 0;
    while(val != 0)
    {
        str[i++] = (val % base) + 48;
        val /= base;
    }
    daochuoi(str,0,i-1);
    
    return i;
}
/**/
void solve()
{
    int i,l;
    long long val;
    char temp[11000];
    i = 0;
    l = 0;
    while(s[i] != 0)
    {
        if(l == 0 && s[i] == '0')
        {
            i++;
            continue;
        }
        temp[l++] = s[i];
        val = chuyenhe(temp,l);
        if(val >= m)
        {
            val %= m;
            l = backbase(temp,val);
        }
        if(!val)
            l = 0;
        i++;
    }

    for(i=0;i<l;i++)
        if(temp[i] != '0')
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}
/**/
bool xuly(char s1[])
{
    int i;
    i = 0;
    while(s1[i] != 0)
    {
        if(s1[i] == '0' || s1[i] == '1')
            s[ds++] = s1[i];
        if(s1[i] == '#')
        {
            s[ds] = 0;
            return true;
        }
        i++;
    }
    return false;
}
/**/
void input()
{
    char s1[10000];
    base = 2;
    ds = 0;
    while(scanf("%s",&s1) == 1)
    {
        if(xuly(s1))
        {
            solve();
            ds = 0;
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
