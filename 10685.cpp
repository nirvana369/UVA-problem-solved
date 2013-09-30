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

#define fi "10685.inp"
#define fo "10685.out"
/**/
using namespace std;
/**/
int pre[5010],d[5010];
map <string, int> mmap;
int n;
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
    int i;
    int kq,nut;
    kq = 0;
    for(i=0;i<n;i++)
    {
        nut = fpre(i);
        d[nut]++;
        if(d[nut] > kq)
           kq = d[nut];
    }
    printf("%d\n",kq);
}
/**/
void input()
{
    int i;
    char s1[100],s2[100];
    int nbac,n1,n2;
    int tg;
    while(scanf("%d %d",&n,&nbac))
    {
        if(!n && !nbac)
            break;
        mmap.clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",&s1);
            mmap[s1] = i;
            pre[i] = i;
            d[i] = 0;
        }
        for(i=0;i<nbac;i++)
        {
            scanf("%s %s",&s1,&s2);
            n1 = fpre(mmap[s1]);
            n2 = fpre(mmap[s2]);
            if(n1 > n2)
            {
                tg = n1;
                n1 = n2;
                n2 = tg;
            }
            if(n2 != n1)
                pre[n2] = n1;
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
