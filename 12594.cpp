#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "12594.inp"
#define fo "12594.out"
/**/
using namespace std;
/**/
int d[300];
int k;
char pn[30000];
/**/
void khoitao()
{
    int i;
    int l;
    l = strlen(pn);
    for(i=0;i<l;i++)
        d[pn[i]] = i;
}
/**/
long gettax(char s[],int vt)
{
    int i,j;
    long val;
    val = 0;
    for(i=vt,j=0;i<vt+k;i++,j++)
        val += (j - d[s[i]]) * d[s[i]];
    return val;
}
/**/
void solve(char s[])
{
    int i;
    int l;
    long val,temp;
    l = strlen(s);
    val = 200000000;
    for(i=0;i<=l-k;i++)
    {
        temp = gettax(s,i);
        if(temp < val)
            val = temp;
    }
    printf("%ld\n",val);
}
/**/
void input()
{
    char temp[30000];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        sscanf(temp,"%s %d",&pn,&k);
        khoitao();
        gets(temp);
        solve(temp);
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
