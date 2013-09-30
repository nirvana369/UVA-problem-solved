/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10878.inp"
#define fo "10878.out"
/**/
using namespace std;
/**/
int getpow(int bac)
{
    int i,gt;
    gt = 1;
    for(i=0;i<bac;i++)
        gt *= 2;
    return gt;
}
/**/
void solve(char s[])
{
    int i;
    int l,value,bac;
    
    l = strlen(s);
    for(i=l-1;i>=0;i--)
        if(s[i] == '|')
        {
            i--;
            break;
        }
    bac = 0;
    value = 0;
    while(i >= 0)
    {
        if(s[i] == '|')
            break;
        if(s[i] == 'o')
            value += getpow(bac);
        if(s[i] != '.')
            bac++;
        i--;
    }
    printf("%c",value);
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        if(temp[0] != '_')
            solve(temp);
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
