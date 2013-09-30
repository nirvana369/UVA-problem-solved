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

#define fi "1226.inp"
#define fo "1226.out"
/**/
using namespace std;
/**/
long n;
char s[3000];
/**/
void solve()
{
    int i;
    int l;
    long long val;
    l = strlen(s);
    val = 0;
    i = 0;
    if(l < 18)
    {
        sscanf(s,"%lld",&val);
        val %= n;
    }
    else
        while(true)
        {
            if(val != 0)
                val %= n;
            if(i == l)
                break;
            val *= 10;
            val += s[i] - 48;
            i++;
        }
    printf("%lld\n",val);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %s",&n,&s);
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
