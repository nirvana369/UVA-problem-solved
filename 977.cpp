/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iostream>

#define fi "977.inp"
#define fo "977.out"
/**/
using namespace std;
/**/
struct billy{
                int xp;
                int t;
            };
queue<billy > q;
vector<billy > a[55];
int rumor[55],nhan[55],kill[55],s[55];
bool d[55];
int n,nroad;
/**/
void spfa()
{
    int i;
    int maxkill,val;
    billy tg,tmp;
    
    for(i=0;i<n;i++)
    {
        nhan[i] = 0;
        d[i] = true;
        s[i] = 30000;
    }
    
    maxkill = 1;
    nhan[0] = 1;
    tmp.xp = 0;
    s[0] = kill[0];
    tmp.t = kill[0];
    
    q.push(tmp);
    
    while(!q.empty())
    {
        tmp = q.front();
        
        q.pop();
        d[tmp.xp] = false;
        
        for(i=0;i<a[tmp.xp].size();i++)
            if(tmp.t + (a[tmp.xp][i].t / 2) <= rumor[a[tmp.xp][i].xp] && nhan[tmp.xp] + 1 >= nhan[a[tmp.xp][i].xp])
            {
                if(nhan[tmp.xp] + 1 == nhan[a[tmp.xp][i].xp])
                {
                    val = tmp.t + (a[tmp.xp][i].t / 2) + kill[a[tmp.xp][i].xp];
                    if(val > s[a[tmp.xp][i].xp])
                        continue;
                }
                
                nhan[a[tmp.xp][i].xp] = nhan[tmp.xp] + 1; // kill + 1 rumor
                
                if(nhan[a[tmp.xp][i].xp] > maxkill) // update max kill
                    maxkill = nhan[a[tmp.xp][i].xp];
                
                tg.t = tmp.t + (a[tmp.xp][i].t / 2) + kill[a[tmp.xp][i].xp];// time xp + 1/2 travel time + time to kill rumor
                
                tg.xp = a[tmp.xp][i].xp; // add vertex
                
                s[tg.xp] = tg.t;
                
                if(d[tg.xp])
                    q.push(tg);
            }
    }
    
    printf("%d\n",maxkill);
}
/**/
void solve()
{
    int i,j;
    
    // bellman - ford
    for(i=1;i<n;i++)
        rumor[i] = 30000;
    
    rumor[0] = 0;
        
    for(i=0;i<n;i++)
        for(j=0;j<a[i].size();j++)
            if(rumor[i] + a[i][j].t < rumor[a[i][j].xp])
                rumor[a[i][j].xp] = rumor[i] + a[i][j].t;
    
    spfa();
}
/**/
void input()
{
    billy tmp;
    int i;
    int x,y;
    
    while(scanf("%d %d",&n,&nroad) == 2)
    {
        for(i=0;i<n;i++)
        {
            a[i].clear();
            scanf("%d",&kill[i]);
        }
        for(i=0;i<nroad;i++)
        {
            scanf("%d %d %d",&x,&y,&tmp.t);
            tmp.xp = y;
            a[x].push_back(tmp);
            tmp.xp = x;
            a[y].push_back(tmp);
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
