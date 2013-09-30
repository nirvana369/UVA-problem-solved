/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "10802.inp"
#define fo "10802.out"
/**/
using namespace std;
/**/
bool a[110][110],d[110],b[110][110];
vector<int > vertex;
int kq[110];
int n,m,s,e;
int f;
/**/
void dfs(int v,int id)
{
    int i;
    
    if(v == e)   
    {
        kq[id] = v;
        f = id;
        return;
    }
    for(i=0;i<vertex.size();i++)
        if(d[vertex[i]] && b[vertex[i]][v])
        {
            kq[id] = vertex[i];
            d[vertex[i]] = false;
            
            dfs(vertex[i],id+1);

            if(f)
                return;
                
            d[vertex[i]] = true;
        }
}
/**/
void resetd(int v)
{
    int i;
    for(i=0;i<n;i++)
        d[i] = false;
        
    vertex.clear();
    for(i=0;i<n;i++)
        if(a[i][v])
        {
            d[i] = true;
            vertex.push_back(i);
        }
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j] = b[i][j] = false;
}
/**/
void solve()
{
    int i,j,k;
    
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][k] && a[k][j])
                    a[i][j] = true;
    
    for(i=0;i<n;i++)
        if(!a[s][i])
            printf("No drive.\n");
        else
        {
            resetd(i);
            f = 0;
            e = i;
            d[s] = false;
            dfs(s,0);
            printf("%d",s);
            for(j=0;j<f;j++)
                printf(" %d",kq[j]);
            printf("\n");
        }
}
/**/
void input()
{
    int i;
    int x,y;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&n,&m,&s);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = a[y][x] = true;
            b[x][y] = b[y][x] = true;
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

