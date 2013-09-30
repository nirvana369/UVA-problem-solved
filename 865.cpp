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

#define fi "865.inp"
#define fo "865.out"
/**/
using namespace std;
/**/
int d[300];
char s1[1000],s2[1000];
/**/
void khoitao()
{
    int i;
    int l;
    l = strlen(s1);
    for(i=0;i<=200;i++)
        d[i] = i;
    for(i=0;i<l;i++)
        d[s1[i]] = s2[i];
    printf("%s\n%s\n",s2,s1);
}
/**/
void solve(char s[])
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
        printf("%c",d[s[i]]);
    printf("\n");
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    gets(s1);
    gets(s1);
    while(ntest--)
    {
        gets(s1);
        gets(s2);
        khoitao();
        while(true)
        {
            s1[0] = 0;
            gets(s1);
            if(s1[0] == 0)
                break;
            solve(s1);
        }
        if(ntest != 0)
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
