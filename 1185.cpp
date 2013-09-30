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

#define fi "1185.inp"
#define fo "1185.out"
#define maxgt 10000000l
/**/
using namespace std;
/**/
long len[maxgt+10];
/**/
/**/
void precal()
{
    long i;
    double val;
    char temp[100];
    int l;
    val = 0;
    for(i=1;i<=maxgt;i++)
    {
        val += log10(i);
        len[i] = (int)val + 1;
    }
}
/**/
void input()
{
    long n;
    int ntest;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        printf("%ld\n",len[n]);
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
