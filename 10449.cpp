/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10449.inp"
#define fo "10449.out"
#define maxgt 1000000000
/**/
using namespace std;
/**/
vector<pair<int,long > > a[210];
long nhan[210];
bool d[210];
int n;
/**/
void dfs(int v)
{
    int i;
    d[v] = false;
    
    for(i=0;i<a[v].size();i++)
        if(d[a[v][i].first])
            dfs(a[v][i].first);
}
/**/
void solve()
{
    int i,j;
    
    nhan[1] = 0;
    for(i=1;i<=n;i++)
        for(j=0;j<a[i].size();j++)
            if(nhan[i] < maxgt && nhan[i] + a[i][j].second < nhan[a[i][j].first])
                nhan[a[i][j].first] = nhan[i] + a[i][j].second;
                
    for(i=1;i<=n;i++)
        for(j=0;j<a[i].size();j++)
            if(nhan[i] < maxgt && nhan[i] + a[i][j].second < nhan[a[i][j].first] && d[i])
                dfs(i);
    
}
/**/
int cube(int val)
{
    return (val * val * val);
}
/**/
void input()
{
    int i;
    int m,id;
    int x,y;
    long tmp;
    long gt[210];
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++)
        {
            a[i].clear();
            d[i] = true;
            nhan[i] = maxgt;
            scanf("%ld",&gt[i]);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            if(x > 0 && x <= n && y > 0 && y <= n)
            {
                tmp = cube(gt[y] - gt[x]);
                a[x].push_back(make_pair(y,tmp));
            }
        }
        solve();
        scanf("%d",&m);
        printf("Set #%d\n",id++);
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            if(x < 1 || x > n || !d[x] || nhan[x] < 3 || nhan[x] == maxgt)
                printf("?\n");
            else
                printf("%ld\n",nhan[x]);
        }
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
