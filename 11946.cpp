/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11946.inp"
#define fo "11946.out"
/**/
using namespace std;
/**/
char s[100],d[100];
/**/
void _init()
{
    d['0'] = 'O';
    d['1'] = 'I';
    d['2'] = 'Z';
    d['3'] = 'E';
    d['4'] = 'A';
    d['5'] = 'S';
    d['6'] = 'G';
    d['7'] = 'T';
    d['8'] = 'B';
    d['9'] = 'P';
}
/**/
void solve()
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            printf("%c",d[s[i]]);
        else
            printf("%c",s[i]);
        i++;    
    }
    
    printf("\n");
}
/**/
void input()
{
    int ntest;
    
    _init();
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        while(true)    
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
            solve();
        }
        if(ntest)
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
