/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "200.inp"
#define fo "200.out"
/**/
using namespace std;
/**/
void input()
{
    int d[100],len[30000];
    char a[30000][30];
    int i,j;
    int id,maxlen;
    for(i=65;i<91;i++)
        d[i] = 0;
    id = 0;
    maxlen = 0;
    while(true)
    {
        gets(a[id]);
        if(a[id][0] == '#')
            break;
        len[id] = strlen(a[id]);
        if(len[id] > maxlen)
            maxlen = len[id];
        id++;
    }
    for(i=0;i<maxlen;i++)
        for(j=0;j<id;j++)
            if(i < len[j] && d[a[j][i]] == 0)
            {
                printf("%c",a[j][i]);
                d[a[j][i]] = 1;
            }
    printf("\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
