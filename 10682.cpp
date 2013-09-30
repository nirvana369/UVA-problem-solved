/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

#define fi "10682.inp"
#define fo "10682.out"
/**/
using namespace std;
/**/        
struct data{
                int x,y,v;
            };
struct drunk{
                int velo;
                int u;
            };
struct drive{
                int s;
                int vt,k;
            };
class sosanh{
public:
    bool operator()(drunk t1,drunk t2)
    {
        return (t1.u > t2.u);
    }    
};
data road[5100];
map<string, int > mmap;
vector<drunk > a[10010];
queue<drive > q;
priority_queue<drunk, vector<drunk >, sosanh > pq;
int trc[10010];
char name[10010][100];
bool d[10010],conn[10010][10010];
int n,m,xp,kt;
/**/

/**/
void khoitao()
{
    int i,j;
    drunk t;
    
    for(i=1;i<n;i++)
    {
        a[i].clear();
        d[i] = true;
    }
    
    for(i=0;i<m;i++)
    {
        t.u = road[i].y;
        t.velo = road[i].v;
        
        a[road[i].x].push_back(t);
        
        t.u = road[i].x;
        a[road[i].y].push_back(t);
        
        conn[road[i].x][road[i].y] = conn[road[i].y][road[i].x] = true;
    }
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<a[i].size();j++)
            pq.push(a[i][j]);
        a[i].clear();
        while(!pq.empty())
        {
            a[i].push_back(pq.top());
            pq.pop();
        }
    }
}
/**/
void output(int x)
{
    if(x == xp)
        return;
    x = trc[x];
    output(x);
    printf("%s ",name[x]);
}
/**/
bool bfs()
{
    int i;
    int dau,cuoi;
    int x,velo;
    drive t,tmp;
    
    while(!q.empty())
        q.pop();
        
    t.s = xp;
    t.vt = 0;
    t.k = xp;
    q.push(t);
    
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        
        for(i=0;i<a[t.s].size();i++)
        {
            x = a[t.s][i].u;
            
            if(a[t.s][i].velo >= t.vt && conn[t.s][x])
            {
                tmp.s = x;
                tmp.vt = a[t.s][i].velo;              
                  
                trc[t.s] = t.k;
                trc[tmp.s] = t.s;

                tmp.k = t.s;
                if(x == kt)
                    return true;

                q.push(tmp);
                conn[t.s][x] = conn[x][t.s] = false;
            }
        }
    }
    return false;
}
/**/
void input()
{
    int i;
    int id1,id2,id;
    char s[100];
    int gt;
    bool route;
    
    id = 0;
    while(scanf("%d",&m) == 1)
    {
        if(id)
            printf("\n");
            
        n = 1;
        mmap.clear();
        for(i=0;i<m;i++)
        {
            scanf("%s",&s);
            id1 = mmap[s];
            
            if(!id1)
            {
                id1  = n;
                strcpy(name[n],s);
                mmap[s] = n++;
            }
            
            scanf("%s %d",&s,&road[i].v);
            id2 = mmap[s];
            
            if(!id2)
            {
                id2  = n;
                strcpy(name[n],s);
                mmap[s] = n++;
            }
            
            road[i].x = id1;
            road[i].y = id2;
        }
        khoitao();
        scanf("%s",&s);
        xp = mmap[s];
        scanf("%s",&s);
        kt = mmap[s];
        
        route = false;
        
        if(xp && kt)
            route = bfs();
        
        if(route)
        {
            output(kt);
            printf("%s\n",name[kt]);
        }
        else
            printf("No valid route.\n");
        id++;
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
