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

#define fi "11770.inp"
#define fo "11770.out"
/**/
using namespace std;
/**/
vector<int> a[10010],luu;
bool d[10010],d1[10010];
int q[10010];
int n;
long m;
/**/
void go(int dinh)
{
    int i;
    if(d1[dinh])
        return;
    d1[dinh] = true;
    for(i=0;i<a[dinh].size();i++)
        if(!d1[a[dinh][i]])
            go(a[dinh][i]);
            
    luu.push_back(dinh);
}
/**/
void loang(int xp)
{
    int i;
    int dau,cuoi;
    dau = -1;
    cuoi = 0;
    q[cuoi] = xp;
    d[xp] = true;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<a[q[dau]].size();i++)
            if(!d[a[q[dau]][i]])
            {
                cuoi++;
                d[a[q[dau]][i]] = true;
                q[cuoi] = a[q[dau]][i];
            }
    }
}
/**/
void solve(int id)
{
    int i;
    int turn;
    
    for(i=1;i<=n;i++)
        if(!d1[i])
            go(i);
    turn = 0;
    for(i=luu.size()-1;i>=0;i--)
        if(!d[luu[i]])
        {
            loang(luu[i]);
            turn++;
        }
    printf("Case %d: %d\n",id,turn);
}
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
    {
        a[i].clear();
        d[i] = d1[i] = false;
    }
    luu.clear();
}
/**/
void input()
{
    long i;
    int x,y;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %ld",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            a[x].push_back(y);
        }
        solve(id++);        
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
