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

#define fi "12416.inp"
#define fo "12416.out"
/**/
using namespace std;
/**/
char s[10000000];
/**/
void solve()
{
    int i;
    long dem,sp;
    sp = 1;
    i = 0;
    dem = 0;
    while(s[i] != 0)
    {
        if(s[i] != ' ')
        {
            sp = sp < dem ? dem : sp;
            dem = 0;
        }
        else
            dem++;
        i++;
    }
    dem = 0;
    while(sp != 1)
    {
        if(sp % 2 != 0)
            sp += 1;
        sp /= 2;
        dem++;
    }
    printf("%ld\n",dem);
}
/**/
void input()
{
    while(true)
    {
        s[0] = 0;
        gets(s);
        if(!s[0])
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
