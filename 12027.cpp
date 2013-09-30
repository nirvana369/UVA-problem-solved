/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12027.inp"
#define fo "12027.out"
/**/
using namespace std;
/**/
char s[1100];
int len;
/**/
void solve()
{
    int l,val;
    int i;
    char tmp[1100];
    
    if(len % 2 == 0)
        val = (s[0] - 48) * 10 + (s[1] - 48);
    else
        val = s[0] - 48;
        
    len = len / 2 + len % 2;    
    val = (int)sqrt(val);
    sprintf(tmp,"%d",val);
    l = strlen(tmp);
    if(l < len)
    {
        for(i=l;i<len;i++)
            tmp[i] = '0';
        tmp[len] = 0;
    }
    printf("%s\n",tmp);
}
/**/
void input()
{
    while(true)
    {
        scanf("%s",&s);
        len = strlen(s);
        if(s[0] == '0' && len == 1)
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
