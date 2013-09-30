/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "11518.inp"
#define fo "11518.out"
/**/
using namespace std;
/**/
vector<int > dmn[10010];
bool d[10010];
int q[10010];
int n,m,l,fall;
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++) 
    {
        d[i] = true;
        dmn[i].clear();
    }
}
/**/
void loang(int xp)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    
    q[cuoi] = xp;
    d[xp] = false;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<dmn[q[dau]].size();i++)
            if(d[dmn[q[dau]][i]])
            {
                d[dmn[q[dau]][i]] = false;
                cuoi++;
                q[cuoi] = dmn[q[dau]][i];
                fall++;
            }
    }
}
/**/
void input()
{
    int i;
    int x,y;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&n,&m,&l);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            dmn[x].push_back(y);
        }
        fall = 0;
        for(i=0;i<l;i++)
        {
            scanf("%d",&x);
            if(d[x])
            {
                fall++;
                loang(x);
            }
        }
        printf("%d\n",fall);
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
