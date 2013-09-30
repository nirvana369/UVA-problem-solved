/*
                                                        Hoang Linh
                                                        
                                                           SPFA
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define fi "11492.inp"
#define fo "11492.out"
#define maxval 1000000000
/**/
using namespace std;
/**/
struct bab{
                char kt;
                long l;
                int v;
            };
vector<bab > a[4010];
queue<bab > q;
map<string, int > mmap;
bool d[4010][30];
long nhan[4010][30];
int n,dau,cuoi;
/**/
void solve()
{
    int i,j;
    bab t1,t2;
    long len,ans;
    int u;
    char c;
    
    for(i=1;i<n;i++)
        for(j=0;j<=27;j++)
            nhan[i][j] = maxval;

    for(i=0;i<=27;i++)
        nhan[dau][i] = 0;

    t1.v = dau;
    t1.l = 0;
    t1.kt = 0;
    q.push(t1);
    
    while(!q.empty())
    {
        t1 = q.front();
        q.pop();
        
        for(i=0;i<a[t1.v].size();i++)
        {
            len = a[t1.v][i].l;
            u = a[t1.v][i].v;
            c = a[t1.v][i].kt;
            if(len + nhan[t1.v][t1.kt] < nhan[u][c] && c != t1.kt)
            {
                nhan[u][c] = len + nhan[t1.v][t1.kt];
                t2.v = u;
                t2.l = nhan[u][c];
                t2.kt = c;
                q.push(t2);
            }
        }
    }
    ans = maxval;
    for(i=0;i<=27;i++)
        ans = min(ans,nhan[cuoi][i]);
    if(ans == maxval)
        printf("impossivel\n");
    else
        printf("%ld\n",ans);
}
/**/
void input()
{
    int i;
    int m;
    int x,y;
    bab t;
    char s[1000];
    
    while(scanf("%d",&m) && m)
    {
        mmap.clear();
        n = 1;
        a[1].clear();
        a[2].clear();
        scanf("%s",&s);
        mmap[s] = n;
        dau = n++;
        scanf("%s",&s);
        cuoi = mmap[s];
        if(!cuoi)
        {
            mmap[s] = n;
            cuoi = n++;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",&s);
            x = mmap[s];
            if(!x)
            {
                mmap[s] = n;
                a[n].clear();
                x = n++;
            }
            
            scanf("%s",&s);
            y = mmap[s];
            if(!y)
            {
                mmap[s] = n;
                a[n].clear();
                y = n++;
            }
            scanf("%s",&s);
            t.l = strlen(s);
            t.kt = s[0] - 96;
            t.v = y;
            a[x].push_back(t);
            t.v = x;
            a[y].push_back(t);
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
