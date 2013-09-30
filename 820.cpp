/*
                                                        Hoang Linh
                                                        
                                            maximum flow - > Edmonds Krap’s
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
//#include <vector>
//#include <map>

#define fi "820.inp"
#define fo "820.out"
#define maxval 2000000000l
/**/
using namespace std;
/**/
int a[110][110];
int pre[110];
queue<int > q;
int n,m,xp,kt;
/**/
void _rs()
{
    int i;
    
    for(i=1;i<=n;i++)
        pre[i] = 0;
        
    while(!q.empty())
        q.pop();
}
/**/
bool bfs()
{
    int i;
    int v;
    
    _rs();
    q.push(xp);
    pre[xp] = xp;
    
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        
        if(v == kt)        
            return true;
            
        for(i=1;i<=n;i++)
            if(!pre[i] && a[v][i])
            {
                pre[i] = v;
                q.push(i);
            }
    }
    
    return false;
}
/**/
void solve(int id)
{
    long cost,w;
    int v;
    
    cost = 0;
    
    while(bfs())
    {
        v = kt;
        w = maxval;
        while(v != pre[v])
        {
            w = w > a[pre[v]][v] ? a[pre[v]][v] : w;
            v = pre[v];
        }
        
        cost += w;
        v = kt;
        
        while(v != pre[v])
        {
            a[pre[v]][v] -= w;
            a[v][pre[v]] += w;
            v = pre[v];
        }
    }
    
    printf("Network %d\nThe bandwidth is %ld.\n\n",id,cost);
}
/**/
void _init()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = 0;
}
/**/
void input()
{
    int x,y,c;
    int id;
    
    id = 1;
    while(scanf("%d",&n) && n)
    {
        scanf("%d %d %d",&xp,&kt,&m);
        _init();
        while(m--)
        {
            scanf("%d %d %d",&x,&y,&c);
            a[x][y] += c; 
            a[y][x] += c;
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
