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

#define fi "1215.inp"
#define fo "1215.out"
/**/
using namespace std;
/**/
struct tree{
                int dau,cuoi;
            };
tree t[10000];
char s[10010];
int a[1100];
int n;
long val;
/**/
int kiemtra(int xp,int mid,int kt)
{
    int i;
    int d1[125],d2[125];
    int dem;
    for(i='a';i<='z';i++)
    {
        d1[i] = 0;
        d2[i] = 0;
    }
    for(i=xp;i<=mid;i++)
        d1[s[i]] = 1;
    for(i=mid+1;i<=kt;i++)
        d2[s[i]] = 1;
    dem = 0;
    for(i='a';i<='z';i++)
        if(d1[i] && !d2[i] || !d1[i] && d2[i])
            dem++;
    return dem;
}
/**/
void solve()
{
    int i,j;
    int id;
    t[1].dau = 0;
    t[1].cuoi = a[0];
    t[2].dau = a[0] + 1;
    t[2].cuoi = strlen(s)-1;
    id = 2;
    val = kiemtra(t[1].dau,a[0],t[2].cuoi);

    for(i=1;i<n;i++)
    {
        j = id;
        while(j >= 0)
        {
            if(a[i] >= t[j].dau && a[i] <= t[j].cuoi)
            {
                val += kiemtra(t[j].dau,a[i],t[j].cuoi);
                id++;
                t[id].dau = t[j].dau;
                t[id].cuoi = a[i];
                id++;
                t[id].dau = a[i]+1;
                t[id].cuoi = t[j].cuoi;
                break;
            }
            j--;
        }
    }
    printf("%ld\n",val);
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]--;
        }
        scanf("%s",&s);
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
