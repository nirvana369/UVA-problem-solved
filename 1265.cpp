/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <iostream>

#define fi "1265.inp"
#define fo "1265.out"
#define maxval 1000100
/**/
using namespace std;
/**/
struct tb{
            int x,y;
            long w;
        };
        
class sosanh{
public:
    bool operator()(tb u,tb v)
    {
        if(u.w < v.w)
            return true;
        return false;
    }    
};
long ts[5010][5010];
int pre[5010];
priority_queue<tb, vector<tb>, sosanh > pq;
vector<int > a[5010], g[5010];
int n;
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)
    {
        pre[i] = i;
        a[i].clear();
        g[i].clear();
        a[i].push_back(i);
    }
    
    while(!pq.empty())
        pq.pop();
}
/**/
int fpre(int v)
{
    while(v != pre[v])
        v = pre[v];
    return v;
}
/**/
void solve()
{
    tb tmp;
    int i,j,u,v;
    int x,y;
    bool add;
    long mingt,maxgt,edge;
    
    edge = 0;
    while(!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        u = fpre(tmp.x);
        v = fpre(tmp.y);
        if(u != v)
        {
            pre[v] = u;
            pre[tmp.x] = u;
            pre[tmp.y] = u;
            
            for(i=0;i<a[v].size();i++)      // add dinh vao cay
                a[u].push_back(a[v][i]);

            mingt = maxval;
            maxgt = -1;   
            a[v].clear();

            for(i=0;i<a[u].size();i++) //
            {
                x = a[u][i];
                for(j=0;j<g[x].size();j++)
                {
                    y = fpre(g[x][j]);   
                    if(y != u)
                        maxgt = ts[x][g[x][j]] > maxgt ? ts[x][g[x][j]] : maxgt; // max gia tri vung ngoai
                    else
                        mingt = ts[x][g[x][j]] < mingt ? ts[x][g[x][j]] : mingt; // mingt vung trong
                }
            }
    
            
            if(mingt > maxgt)
                edge += a[u].size();
        }
    }
    printf("%ld\n",edge);
}
/**/
void input()
{
    tb t;
    int i;
    int m;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %ld",&t.x,&t.y,&t.w);
            ts[t.x][t.y] = ts[t.y][t.x] = t.w;
            g[t.x].push_back(t.y);
            g[t.y].push_back(t.x);
            pq.push(t);
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
