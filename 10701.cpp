/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10701.inp"
#define fo "10701.out"
/**/
using namespace std;
/**/
int n;
char in[1010],post[1010],pre[1010];
char kt;
/**/
void khoitao()
{
    int i;
    for(i=1;i<1000;i++)
        post[i] = 0;
}
/**/
void mtree(int id,int dau,int cuoi)
{
    int i,j;
    
    if(post[id] == 0)
    {
        post[id] = kt;
        return;
    }
    else
    {
        for(i=dau;i<=cuoi;i++)
            if(in[i] == post[id])
                break;
        for(j=dau;j<i;j++)
            if(kt == in[j])
            {
                mtree(id*2,dau,i-1);
                return;
            }
        for(j=i+1;j<=cuoi;j++)
            if(kt == in[j])
            {
                mtree(id*2+1,i+1,cuoi);
                return;
            }
    }
}
/**/
void output(int id)
{
    if(post[id] == 0)
        return;
    output(id*2);
    output(id*2+1);
    printf("%c",post[id]);
}
/**/
void solve()
{
    int i;
    khoitao();
    for(i=0;i<n;i++)
    {
        kt = pre[i];
        mtree(1,0,n-1);
    }
    output(1);
    printf("\n");
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %s %s",&n,&pre,&in);
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
