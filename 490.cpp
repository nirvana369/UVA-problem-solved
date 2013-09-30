/*
                                                    Hoang Linh
                                                    
                                        Problem: ROTATING SENTENCES - 490 (490.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "490.inp"
#define fo "490.out"
/**/
using namespace std;
/**/
char s[110][200];
int l[110];
int maxs,maxlen;
/**/
void solve()
{
    int i,j;

    for(j=0;j<maxlen;j++)
    {
        for(i=maxs-1;i>=0;i--)
        {
            if(j < l[i])
                printf("%c",s[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
}
/**/
void input()
{
    maxs = 0;
    maxlen = 0;
    
    while(!feof(stdin))
    {
        gets(s[maxs]);
        if(feof(stdin))
            break;
        l[maxs] = strlen(s[maxs]);
        if(l[maxs] > maxlen)
            maxlen = l[maxs];
        maxs++;
    }
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
