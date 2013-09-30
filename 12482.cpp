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

#define fi "12482.inp"
#define fo "12482.out"
/**/
using namespace std;
/**/
int n,wpl,line;
int a[1100];
/**/
void solve()
{
    int i;
    int page,ln,dong;
    page = 0;
    i = 0;
    ln = 0;
    dong = 0;
    while(true)
    {
        while(dong + a[i] <= wpl)
        {
            dong += a[i];
            dong++;
            i++;
            if(i == n)
                break;
        }
        ln++;
        dong = 0;
        if(ln == line)
        {
            page++;
            ln = 0;
        }
        if(i == n)
            break;
    }
    if(ln != 0)
        page++;
    printf("%d\n",page);
}
/**/
void input()
{
    int i;
    char s[1000];
    while(scanf("%d %d %d",&n,&line,&wpl) == 3)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",&s);
            a[i] = strlen(s);
        }
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
