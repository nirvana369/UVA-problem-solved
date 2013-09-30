/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10679.inp"
#define fo "10679.out"
/**/
using namespace std;
/**/
vector<int > vt[130];
int d[130],len[1100],d1[1100];
char s[1000010],a[1100][1100];
int n;
/**/
void solve()
{
    long i,j;
    int maxf,tmp,id;
    int dau1,cuoi1,dau2,cuoi2;
    
    i = 0;
    maxf = 0;
    while(s[i])
    {
        if(d[s[i]])
        {
            tmp = s[i];
            for(j=0;j<vt[tmp].size();j++)
            {
                id = vt[tmp][j];
                if(!d1[id])
                {
                    dau1 = i;
                    cuoi1 = i + len[id] - 1;
                    dau2 = 0;
                    cuoi2 = len[id] - 1;
                    while(dau2 <= cuoi2)
                    {
                        if(s[dau1] != a[id][dau2])
                            break;
                        if(s[cuoi1] != a[id][cuoi2])
                            break;
                        dau1++;
                        dau2++;
                        cuoi1--;
                        cuoi2--;
                    }
                    if(dau2 > cuoi2)
                        d1[id] = 1;
                }
            }
        }
        i++;
    }
    
    for(i=0;i<n;i++)
        if(d1[i])
            printf("y\n");
        else
            printf("n\n");
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<=126;i++)
    {
        d[i] = 0;
        vt[i].clear();
    }
}
/**/
void input()
{
    int ntest;
    int i;
    int tmp;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        khoitao();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            len[i] = strlen(a[i]);
            d1[i] = 0;
            tmp = a[i][0];     
            d[tmp] = 1;
            vt[tmp].push_back(i);
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
