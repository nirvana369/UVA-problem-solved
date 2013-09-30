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

#define fi "10093.inp"
#define fo "10093.out"
/**/
using namespace std;
/**/
int d[200],gt[200];
void _init()
{
    int i,base;
    base = 3;
    gt['0'] = 0;
    gt['1'] = 1;
    d['0'] = 2;
    d['1'] = 2;
    for(i='2';i<='9';i++,base++)
    {
        d[i] = base;
        gt[i] = base - 1;
    }
    for(i='A';i<='Z';i++,base++)
    {
        d[i] = base;
        gt[i] = base - 1;
    }
    for(i='a';i<='z';i++,base++)
    {
        d[i] = base;
        gt[i] = base - 1;
    }
}
/**/
int solve(char s[])
{
    int val;
    int i,base,j;
    
    i = j = 0;
    base = val = 0;
    while(s[i] != 0)
    {
        if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
        {
            if(d[s[i]] > base)
                base = d[s[i]];
            s[j++] = s[i];
            val += gt[s[i]];
        }
        i++;
    }
    if(base < 2)
        return -1;
    while(base < 63)
    {
        if(val % (base-1) == 0)
            return base;
        base++;
    }
    return -1;
}
/**/
void input()
{
    char s[10000];
    int kq;
    _init();
    while(scanf("%s",&s) == 1)
    {
        kq = solve(s);
        if(kq == -1)
            printf("such number is impossible!\n");
        else
            printf("%d\n",kq);
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
