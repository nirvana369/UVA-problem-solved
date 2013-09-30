/*
                                                    Hoang Linh
                                                    
                                      Problem: ALL YOU NEED IS LOVE - 10193 (10193.*)  
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10193.inp"
#define fo "10193.out"
/**/
using namespace std;
/**/
long long a,b;
/**/
void ucln()
{
    long r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
}
/**/
long long laybac(int gt,int bac)
{
    int i;
    long long value;
    if(bac == 0)
        return 1;
    value = gt;
    for(i=1;i<bac;i++)
        value *= gt;
    return value;
}
/**/
long long xuly(char s[])
{
    int i;
    int l,bac;
    long long value;
    l = strlen(s);
    bac = l - 1;
    value = 0;
    for(i=0;i<l;i++,bac--)
        value = value + (s[i] - 48) * laybac(2,bac);
    return value;
}
/**/
void input()
{
    char temp[10000];
    int ntest;
    int id;
    scanf("%d",&ntest);
    gets(temp);
    id = 1;
    while(ntest--)
    {
        gets(temp);
        a = xuly(temp);
        gets(temp);
        b = xuly(temp);
        ucln();
        if(a != 1)
            printf("Pair #%d: All you need is love!\n",id);
        else
            printf("Pair #%d: Love is not all you need!\n",id);
        id++;
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
