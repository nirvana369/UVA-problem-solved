/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11933.inp"
#define fo "11933.out"
/**/
using namespace std;
/**/
char sn[50],a[50],b[50];
int vt[1000];
long n,an,bn;
int lenn;
/**/
void cbinary(char s[],long val)
{
    int i,j;
    i = 0;
    j = 1;
    while(val != 0)
    {
        if(val % 2 != 0)
        {
            s[i] = '1';
            vt[i] = j++;
        }
        else
        {
            s[i] = '0';
            vt[i] = 0;
        }
        i++;
        val /= 2;
    }
    lenn = i-1;
}
/**/
long expon(int mu)
{
    int i;
    long val;
    val = 1;
    for(i=0;i<mu;i++)
        val *= 2;
    return val;
}
/**/
long cdecimal(char s[])
{
    int i;
    long val;
    
    val = 0;
    for(i=lenn;i>=0;i--)
        if(s[i] == '1')
            val += expon(i);
    return val;
}
/**/
void solve()
{
    int i;
    
    for(i=lenn;i>=0;i--)
    {
        if(!vt[i])
        {
            a[i] = sn[i];
            b[i] = sn[i];
        }
        else
        {
            if(vt[i] % 2 != 0)
            {
                a[i] = '0';
                b[i] = sn[i];
            }
            else
            {
                a[i] = sn[i];
                b[i] = '0';
            }
        }
    }
    an = cdecimal(a);
    bn = cdecimal(b);
    printf("%ld %ld\n",bn,an);
}
/**/
void input()
{
    while(scanf("%ld",&n) && n)
    {
        cbinary(sn,n);
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
