/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10557.inp"
#define fo "10557.out"
#define maxgt -32767
/**/
using namespace std;
/**/
int e[110],nhan[110];
vector<int > a[110];
bool d[110];
int n;
/**/
void dfs(int v)
{
    int i;
    d[v] = false;
    for(i=0;i<a[v].size();i++)
        if(d[a[v][i]])
            dfs(a[v][i]);
}
/**/
bool solve()
{
    int i,j;
    
    nhan[0] = 100;

    for(i=0;i<n;i++)
        for(j=0;j<a[i].size();j++)
            if(nhan[i] > 0 && nhan[i] + e[a[i][j]] > nhan[a[i][j]])
                nhan[a[i][j]] = nhan[i] + e[a[i][j]];
    
    for(i=0;i<n;i++)
        for(j=0;j<a[i].size();j++)
            if(nhan[i] > 0 && nhan[i] + e[a[i][j]] > nhan[a[i][j]])
                dfs(i);
    
    if(!d[n-1] || nhan[n-1] > 0)
        return true;
    return false;
}
/**/
void input()
{
    int i,j;
    int m,y;
    
    while(scanf("%d",&n))
    {
        if(n < 0)
            break;
        for(i=0;i<n;i++)
        {
            a[i].clear();
            d[i] = true;
            nhan[i] = maxgt;
            scanf("%d %d",&e[i],&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&y);
                y -= 1;
                a[i].push_back(y);
            }
        }
        if(solve())
            printf("winnable\n");
        else
            printf("hopeless\n");
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
