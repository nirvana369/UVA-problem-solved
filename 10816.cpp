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

#define fi "10816.inp"
#define fo "10816.out"
/**/
using namespace std;
/**/
struct des{
                int go;
                double kc,r;
            };
bool d[110];
int trc[110];
vector<des > a[110];
queue<des > q;
double tem[110],dist[110];
int n,m,xp,kt;

//double maxtmp;
//double nd[110][110];
//bool conn[110][110];
/**/
void khoitao()
{
    int i,j;
    
  /*  for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            nd[i][j] = 100;
            conn[i][j] = false;
        }*/
    
    for(i=1;i<=n;i++)
    {
        d[i] = true;
        a[i].clear();
        tem[i] = 100;
        dist[i] = 1000000;
    }
}
/**/
void proad(int x)
{
    if(x == xp)
        return;
    x = trc[x];
    proad(x);
    printf("%d ",x);
}
/**/
void solve()
{
    int i;
    des t,tmp;
    int y;
    double nhietdo,dodai;
    
    t.go = xp;
    t.r = -1;
    t.kc = 0;
    
    tem[xp] = 0;
    dist[xp] = 0;
    
    q.push(t);
    
    while(!q.empty())
    {
        t = q.front();
        q.pop();

        if(t.go == kt)
            continue;
            
        d[t.go] = false;

        for(i=0;i<a[t.go].size();i++)
        {
            y = a[t.go][i].go;
            dodai = a[t.go][i].kc;
            nhietdo = max(a[t.go][i].r,t.r);

            if(nhietdo < tem[y])
            {
                tem[y] = nhietdo;
                tmp.r = nhietdo;
                dist[y] = t.kc + dodai;
                trc[y] = t.go;

                if(d[y])
                {
                    tmp.go = y;
                    tmp.kc = dist[y];
                    q.push(tmp);
                }
            }
            else if(nhietdo == tem[y])
                if(t.kc + dodai < dist[y])
                {
                    tmp.r = nhietdo;
                    dist[y] = t.kc + dodai;
                    trc[y] = t.go;
    
                    if(d[y])
                    {
                        tmp.go = y;
                        tmp.kc = dist[y];
                        q.push(tmp);
                    }   
                }
        }
    }
    // print
    proad(kt);
    printf("%d\n%0.1lf %0.1lf\n",kt,dist[kt],tem[kt]);
}
/**
double floyd()
{
    int i,j,k;
    double tmp;
    
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(conn[i][k] && conn[k][j])
                {
                    conn[i][j] = true;
                    tmp = max(nd[i][k],nd[k][j]);
                    if(nd[i][j] > max(nd[i][k],nd[k][j]))
                        nd[i][j] = tmp;
                }
            }
    return nd[xp][kt];
}
/**/
void input()
{
    int i;
    des t;
    int x,y;
    
    while(scanf("%d %d",&n,&m) == 2)
    {
        khoitao();
        scanf("%d %d",&xp,&kt);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %lf %lf",&x,&y,&t.r,&t.kc);
            t.go = y;
            a[x].push_back(t);
            t.go = x;
            a[y].push_back(t);
            
          //  nd[x][y] = nd[y][x] = t.r;
          //  conn[x][y] = conn[y][x] = true;
        }
        //maxtmp = floyd();
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
