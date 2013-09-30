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

#define fi "1197.inp"
#define fo "1197.out"
/**/
using namespace std;
/**/
int n,m;
int pre[30100];
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
void output()
{
    int i,s1;
    int dem;
    dem = 0;
    s1 = fpre(0);
    for(i=0;i<n;i++)
    {
        if(fpre(i) == s1)
            dem++;
    }
    printf("%d\n",dem);
}
/**/
void input()
{
    int s1,s2;
    int i,k;
    int ns;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        khoitao();
        for(k=0;k<m;k++)
        {
            scanf("%d %d",&ns,&s1);
            s1 = fpre(s1);
            for(i=1;i<ns;i++)
            {
                scanf("%d",&s2);
                s2 = fpre(s2);
                if(s2 != s1)
                    pre[s2] = s1;
            }
        }
        output();
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
