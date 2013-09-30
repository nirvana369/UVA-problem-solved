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
#include <vector>

#define fi "11690.inp"
#define fo "11690.out"
/**/
using namespace std;
/**/
int pre[10010];
long mn[10010];
int n;
/**/
void khoitao()
{
    int i;
    for(i=0;i<n;i++)
        pre[i] = i;
}
/**/
int fpre(int nut)
{
    while(nut != pre[nut])
        nut = pre[nut];
    return nut;
}
/**/
bool solve()
{
    int i;
    long temp;
    int id1;
    for(i=0;i<n;i++)
    {
        id1 = fpre(i);
        temp = mn[i];
        mn[i] = 0;
        mn[id1] += temp;
    }

    for(i=0;i<n;i++)
        if(mn[i] != 0)
            return false;
    return true;
}
/**/
void input()
{
    int ntest;
    int id1,id2;
    long i;
    long m;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %ld",&n,&m);
        khoitao();
        for(i=0;i<n;i++)
            scanf("%ld",&mn[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&id1,&id2);
            pre[fpre(id2)] = fpre(id1);
        }
        if(solve())
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
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
