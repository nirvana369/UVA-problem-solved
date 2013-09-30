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

#define fi "10851.inp"
#define fo "10851.out"
/**/
using namespace std;
/**/
char a[12][1000];
int mu2[10],d[200];
/**/
int getascii(char c)
{
    int i;
    int val;
    val = 0;
    for(i=0;i<8;i++)
    {
        val *= 2;
        val += c / mu2[i] % 2;
    }
    return val;
}
/**/
void precal()
{
    int i;
    for(i=0;i<8;i++)
    {
        mu2[i] = 1;
        mu2[i] <<= i;
    }
    for(i=0;i<128;i++)
        d[getascii(i)] = i;
}
/**/
void input()
{
    int ntest;
    int i,j,l;
    int val;
    
    precal();
    scanf("%d",&ntest);
    gets(a[0]);
    while(ntest--)
    {
        for(i=0;i<11;i++)
            gets(a[i]);
            
        l = strlen(a[1]);
        
        for(i=1;i<l-1;i++)
        {
            val = 0;
            for(j=1;j<9;j++)
            {
                val *= 2;
                val += (a[j][i] == '/') ? 0:1;
            }
            printf("%c",d[val]);
        }
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
