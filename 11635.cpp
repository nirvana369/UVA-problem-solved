/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
//#include <map>

#define fi "11635.inp"
#define fo "11635.out"
/**/
using namespace std;
/**/
struct book{
                int xp,slp,min;
            };
queue<book > q;
vector<pair<int, int> > a[10010];
int n,m,nhotel;
bool ht[10010],d[10010];
int lbl[10010][110];
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
    {
        d[i] = true;
        a[i].clear();
        ht[i] = false;
        for(j=0;j<101;j++)
            lbl[i][j] = 601;
    }
}
/**/
void solve()
{
    int i;
    book t,tmp;
    
    t.xp = 1;
    t.slp = 0;
    t.min = 0;
    lbl[t.xp][t.slp] = 0;
    q.push(t);
    
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        d[t.xp] = false;
        
        if(ht[t.xp])
            {
                lbl[t.xp][t.slp + 1] = 0;
                tmp = t;
                if(t.slp + 1 <= nhotel)
                {
                    tmp.slp = t.slp + 1;
                    tmp.min = 0;
                    q.push(tmp);
                }
            }
            
        for(i=0;i<a[t.xp].size();i++)
        {
            if(t.min + a[t.xp][i].second < lbl[a[t.xp][i].first][t.slp])
            {
                lbl[a[t.xp][i].first][t.slp] = t.min + a[t.xp][i].second;
                tmp.xp = a[t.xp][i].first;
                tmp.slp = t.slp;
                tmp.min = lbl[a[t.xp][i].first][t.slp];
                //if(d[tmp.xp])
                    q.push(tmp); // 
            }
        }
    }
    
    for(i=0;i<101;i++)
        if(lbl[n][i] != 601)
        {
            printf("%d\n",i);
            return;
        }
    printf("-1\n");
}
/**/
void input()
{
    int i;
    int x,y;
    int tg,tmp;
    
    while(scanf("%d",&n) && n)
    {
        khoitao();
        scanf("%d",&nhotel);
        for(i=0;i<nhotel;i++)
        {
            scanf("%d",&tmp);
            ht[tmp] = true;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&tg);
            a[x].push_back(make_pair(y,tg));
            a[y].push_back(make_pair(x,tg));
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
