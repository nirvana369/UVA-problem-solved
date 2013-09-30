/*
                                                        Hoang Linh
                                                        
                                                maximum flow -> Edmonds Krap's
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
//#include <vector>
//#include <map>

#define fi "10480.inp"
#define fo "10480.out"
/**/
using namespace std;
/**/
long long a[55][55];
bool d[55][55];
int pre[55];
queue<int > q;
int n,m,xp,kt;
long long maxval;
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
            if(!pre[i] && a[v][i] > 0)
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
    int i,j;
    long long w;
    int v;
    
    
    while(bfs())
    {
        v = kt;
        w = maxval;
        while(v != pre[v])
        {
            w = w > a[pre[v]][v] ? a[pre[v]][v] : w;
            v = pre[v];
        }
        
        v = kt;
        
        while(v != pre[v])
        {
            a[pre[v]][v] -= w;
            a[v][pre[v]] += w;
            v = pre[v];
        }
    }
    
    for(i=1;i<=n;i++)
        if(pre[i])
            for(j=1;j<=n;j++)
                if(d[i][j] && !pre[j])
                    printf("%d %d\n",i,j);
    printf("\n");
}
/**/
void _init()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            a[i][j] = 0;
            d[i][j] = false;
        }
}
/**/
void input()
{
    int x,y,c;
    int id;
    
    maxval = (long long)pow(2,63);
    xp = 1;
    kt = xp+1;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        _init();
        while(m--)
        {
            scanf("%d %d %d",&x,&y,&c);
            a[x][y] = a[y][x] = c;
            d[x][y] = d[y][x] = true;
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
