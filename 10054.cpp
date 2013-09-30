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
#include <stack>

#define fi "10054.inp"
#define fo "10054.out"
/**/
using namespace std;
/**/
struct road{
                int x,y;
            };
int a[55][55],tt[55],color[55],bac[55];
stack <road> ms;
int n,dcl,dau,cuoi;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<51;i++)
    {
        for(j=1;j<51;j++)
            a[i][j] = 0;
        bac[i] = 0;
        tt[i] = 0;
    }
    dcl = 0;
}
/**/
bool dequy(int xp)
{
    int i;
    road temp;
    for(i=0;i<dcl;i++)
        if(a[xp][color[i]])
        {
            a[xp][color[i]]--;
            a[color[i]][xp]--;
            temp.x = xp;
            temp.y = color[i];
            dequy(color[i]);
            ms.push(temp);
        }
}
/**/
void output()
{
    road temp;
    while(!ms.empty())
    {
        temp = ms.top();
        printf("%d %d\n",temp.x,temp.y);
        ms.pop();
    }
}
/**/
void solve()
{
    int i,j,dem;
    bool coduong;

    for(i=0;i<dcl;i++)
        if(bac[color[i]] % 2 != 0)
        {
            printf("some beads may be lost\n");
            return;
        }
    for(i=0;i<dcl;i++)
        for(j=i+1;j<dcl;j++)
            if(a[color[i]][color[j]])
            {
                dequy(color[i]);
                output();
                return;                
            }
}
/**/
void input()
{
    int i;
    int ntest,id;
    int x,y;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y]++;
            a[y][x]++;
            bac[x]++;
            bac[y]++;
            if(!tt[x])
            {
                color[dcl++] = x;
                tt[x] = 1;
            }
            
            if(!tt[y])
            {
                color[dcl++] = y;
                tt[y] = 1;
            }
        }
        printf("Case #%d\n",id++);
        solve();
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
