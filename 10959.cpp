/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10959.inp"
#define fo "10959.out"
/**/
using namespace std;
/**/
int kc[1010],d[1010],q[1010];
vector<int > a[1010];
int n;
long m;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        a[i].clear();
        d[i] = 0;
        kc[i] = 0;
    }
}
/**/
void loang()
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[cuoi] = 0;
    d[0] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<a[q[dau]].size();i++)
            if(!d[a[q[dau]][i]])
            {
                cuoi++;
                d[a[q[dau]][i]] = 1;
                kc[a[q[dau]][i]] = kc[q[dau]] + 1;
                q[cuoi] = a[q[dau]][i];
            }
    }
}
/**/
void output()
{
    int i;
    for(i=1;i<n;i++)
        printf("%d\n",kc[i]);
}
/**/
void input()
{
    long i;
    int ntest;
    int x,y;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %ld",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            if(x <= 1000 && y <= 1000)
            {
                a[x].push_back(y);
                a[y].push_back(x);
            }
        }
        loang();
        output();
        if(ntest)
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
