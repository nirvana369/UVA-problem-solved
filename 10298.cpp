/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10298.inp"
#define fo "10298.out"
/**/
using namespace std;
/**/
char s[1000100];
/**/
bool sosanh(long c1,long d2)
{
    long i;
    for(i=0;i<c1;i++)
    {
        if(s[i] != s[d2++])
            return false;
    }
    return true;
}
/**/
void solve()
{
    long i,j;
    long l,lvl,bac;
    l = strlen(s);
    bac = 1;
    
    if(l == 0)
    {
        printf("0\n");    
        return;
    }
    for(i=1;i<=l/2;i++)
    {
        lvl = 1;
        if(l % i == 0)
        {
            for(j=i;j<l;j+=i)
                if(sosanh(i,j))
                    lvl++;
                else
                {
                    lvl = 1;
                    break;
                }
            if(lvl > bac)
            {
                bac = l / i;
                break;
            }
        }
    }
    printf("%ld\n",bac);
}
/**/
void input()
{
    while(true)
    {
        gets(s);
        if(s[0] == '.' && strlen(s) == 1)
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
