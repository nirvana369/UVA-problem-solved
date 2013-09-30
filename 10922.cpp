/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10922.inp"
#define fo "10922.out"
/**/
using namespace std;
/**/
char s[10000];
/**/
void solve()
{
    int i;
    int value;
    int l,dem;
    char temp[10000];
    
    strcpy(temp,s);
    dem = 1;
    while(true)
    {
        l = strlen(s);
        value = 0;
        for(i=0;i<l;i++)
            value += s[i] - 48;
        if(value  == 9)
            break;
        if(value % 9 != 0)
            break;
        dem++;
        sprintf(s,"%d",value);
    }
    if(value % 9 != 0)
        printf("%s is not a multiple of 9.\n",temp);
    else
        printf("%s is a multiple of 9 and has 9-degree %d.\n",temp,dem);
}
/**/
void input()
{
    while(true)
    {
        gets(s);
        if(strlen(s) == 1 && s[0] == '0')
            break;
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
