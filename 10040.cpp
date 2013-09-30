/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10040.inp"
#define fo "10040.out"
/**/
using namespace std;
/**/
int n,k;
char bin[5];
long b[24];
/**/
void bintodec(char s[],int lvl)
{
    int i;
    long val;
    
    i = 0;
    val = 0;
    while(s[i])
    {
        if(s[i] == '1')
            val += b[lvl];
        lvl--;
        i++;
    }
    printf("%ld\n",val);
}
/**/
void solve()
{
    int i;
    char tmp[30];
    k %= 4;
    i = 0;
    while(n--)
    {
        tmp[i++] = bin[k++];
        if(k == 4)
            k = 0;
    }
    tmp[i] = 0;
    bintodec(tmp,i-1);
}
/**/
void _init()
{
    int i;
    strcpy(bin,"0011");
    b[0] = 1;
    b[1] = 2;
    for(i=2;i<23;i++)
        b[i] = 2 * b[i-1];
}
void input()
{
    int ntest;
    
    _init();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&k);
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
