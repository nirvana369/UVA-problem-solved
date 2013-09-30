/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <iostream>

#define fi "925.inp"
#define fo "925.out"
/**/
using namespace std;
/**/
bool d[150],a[150][150],b[150][150];
int n,m;
map<string, int > mmap;
vector<int > t,t1;
queue<int> q;
int id[150];
char c[150][200];
int v;
/**/
void sapxep()
{
    int i,j;
    char tmp[100];
    
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(strcmp(c[i],c[j]) > 0)
            {
                strcpy(tmp,c[i]);
                strcpy(c[i],c[j]);
                strcpy(c[j],tmp);
            }
}
/**/
void khoitao()
{
    int i,j;
    
    mmap.clear();
    for(i=1;i<=n;i++)
        mmap[c[i]] = i;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = false;
    }
    while(!q.empty())
        q.pop();
}
/**/
void dfs(int u)
{
    int i;
    
    for(i=1;i<=n;i++)
        if(a[u][i])
            dfs(i);
    t1.push_back(u);
}
/**/
void solve()
{
    int i,j,j1;
    int tmp,x;
    
    for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
            if(id[i] > id[j])
            {
                tmp = id[i];
                id[i] = id[j];
                id[j] = tmp;
            }
            
    for(i=0;i<m;i++)
    {
        t.clear();
        t1.clear();
            
        for(j=1;j<=n;j++)
            if(a[id[i]][j])
            {
                t.push_back(j);
                
                for(j1=1;j1<=n;j1++)
                    if(a[j][j1])
                        q.push(j1);
            }
            
        for(j=1;j<=n;j++)
            d[j] = true;

        tmp = t.size();
        
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            for(j1=1;j1<=n;j1++)
                if(a[x][j1])
                    q.push(j1);
                    
            for(j=0;j<t.size();j++)
                if(t[j] == x && d[x])
                {
                    d[t[j]] = false;
                    tmp--;
                    break;
                }
        }

        printf("%s %d",c[id[i]],tmp);
        for(j=0;j<t.size();j++)
            if(d[t[j]])
                printf(" %s",c[t[j]]);
        printf("\n");
    }
}
/**/
void input()
{
    int i,j,k;
    
    int ntest;
    int x,y;
    char s[200];
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%s",&c[i]);   
        sapxep();
        khoitao();  
        scanf("%d",&m); 
        for(i=0;i<m;i++)
        {
            scanf("%s %d",&s,&k);
            x = mmap[s];
            id[i] = x;
            for(j=0;j<k;j++)
            {
                scanf("%s",&s);
                y = mmap[s];
                a[x][y] = true;
            }
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
