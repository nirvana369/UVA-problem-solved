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

#define fi "11687.inp"
#define fo "11687.out"
/**/
using namespace std;
/**/
char s[1100000],temp[1100000];
/**/
bool sosanh(char s1[],char s2[],long len)
{
    long i;
    for(i=0;i<len;i++)
        if(s1[i] != s2[i])
            return false;
    return true;
}
/**/
void solve()
{
    long l,ltemp;
    int dem;
    l = strlen(s);
    dem = 1;
    while(true)
    {
        sprintf(temp,"%ld",l);
        ltemp = strlen(temp);
        if(l != ltemp)
        {
            strcpy(s,temp);
            l = ltemp;
        }
        else if(sosanh(s,temp,l))
            break;
        else
        {
            strcpy(s,temp);
            l = ltemp;
        }
        dem++;
    }
    printf("%d\n",dem);
}
/**/
void input()
{
    while(true)
    {
        gets(s);
        if(strcmp(s,"END") == 0)
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
