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

#define fi "1263.inp"
#define fo "1263.out"
/**/
using namespace std;
/**/
struct toado{
                long x,y,dist;
            };
class sosanh{
public:
    bool operator()(toado a, toado b)    
    {
        return (a.x > b.x);
    }
};
priority_queue<toado , vector<toado > , sosanh > pq;
toado p[2100];
bool d[2100];
int n;
int q[2100];
vector<int > e[2100],v;
/**/
long _abs(long val)
{
    return val < 0 ? -val : val;
}
/**/
void dfs1(int x)
{
    int i;
    d[x] = false;
    
    for(i=0;i<e[x].size();i++)
        if(d[e[x][i]])
            dfs1(e[x][i]);
            
    v.push_back(x);
}
/**/
void dfs2(int x)
{
    int i;
    d[x] = true;
    
    for(i=0;i<e[x].size();i++)
        if(!d[e[x][i]])
            dfs2(e[x][i]);
}
/**/
void solve()
{
    int i,j;
    int dem;
    
    n = 0;
    while(!pq.empty())
    {
        p[n++] = pq.top();
        pq.pop();
    }
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[j].x - p[i].x > p[i].dist / 2)
                break;
            if(_abs(p[j].y - p[i].y) <= (p[i].dist / 2))
                e[i].push_back(j);
        }
        
        for(j=i-1;j>=0;j--)
        {
            if(p[i].x - p[j].x > p[i].dist / 2)
                break;
            if(_abs(p[j].y - p[i].y) <= (p[i].dist / 2))
                e[i].push_back(j);
        }
    }
    
    // topo sort
    v.clear();
    for(i=0;i<n;i++)
        if(d[i])
            dfs1(i);
    
    dem = 0;
    for(i=v.size()-1;i>=0;i--)
        if(!d[v[i]])
        {
            dfs2(v[i]);
            dem++;
        }
    printf("%d\n",dem);
}
/**/
void input()
{
    int i,j;
    int ntest;
    toado t;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        while(n--)
        {
            e[n].clear();
            d[n] = true;
            scanf("%ld %ld %ld",&t.x,&t.y,&t.dist);
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
