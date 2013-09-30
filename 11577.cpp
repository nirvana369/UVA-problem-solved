/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11577.inp"
#define fo "11577.out"
/**/
using namespace std;
/**/
int d[200];
/**/
void khoitao()
{
    int i;
    for(i=97;i<123;i++)
        d[i] = 0;
}
/**/
void solve(char s[])
{
    int i;
    int l,maxf;
    l = strlen(s);
    maxf = 0;
    for(i=0;i<l;i++)
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            if(s[i] <= 'Z')
                s[i] +=32;
            d[s[i]]++;
            if(d[s[i]] > maxf)
                maxf = d[s[i]];
        }
        
    for(i=97;i<123;i++)
        if(d[i] == maxf)
            printf("%c",i);
    printf("\n");
}
/**/
void input()
{
    char temp[1000];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        khoitao();
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
