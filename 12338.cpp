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

#define fi "12338.inp"
#define fo "12338.out"
/**/
using namespace std;
/**/
char a[100010][10010];
int len[100010];
long n,query;
/**/
int solve(long i1,long i2)
{
    int i;
    int minlen;
    minlen = len[i1] > len[i2] ? len[i2] : len[i1];
    
    for(i=0;i<minlen;i++)
        if(a[i1][i] != a[i2][i])
            return i;
    return i;
}
/**/
void input()
{
    long i,id1,id2,id;
    int ntest;
    int kq;
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        gets(a[0]);
        for(i=1;i<=n;i++)
        {
            gets(a[i]);
            len[i] = strlen(a[i]);
        }
        scanf("%ld",&query);
        printf("Case %d:\n",id++);
        for(i=0;i<query;i++)
        {
            scanf("%ld %ld",&id1,&id2);
            kq = solve(id1,id2);
            printf("%d\n",kq);
        }
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
