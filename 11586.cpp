/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11586.inp"
#define fo "11586.out"
/**/
using namespace std;
/**/
void solve(char s[])
{
    int i;
    int p;
    int d[100];
    
    i = 0;
    d['M'] = d['F'] = 0;
    p = 0;
    while(s[i])
    {
        if(s[i] != ' ')
        {
            d[s[i]]++;
            d[s[i+1]]++;
            p++;
            i++;
        }
        i++;
    }
    if(d['M'] == d['F'] && p > 1)
        printf("LOOP\n");
    else
        printf("NO LOOP\n");
}
/**/
void input()
{
    char s[1000];
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);
        solve(s);
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
