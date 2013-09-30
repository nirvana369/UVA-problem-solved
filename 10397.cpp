/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10397.inp"
#define fo "10397.out"
/**/
using namespace std;
/**/
struct campus{
                int dau,cuoi;
                double dodai;
            };
            
struct toado{
                int x,y;    
            };
            
class sosanh{
public:
    bool operator()(campus t1,campus t2)
    {
        if(t1.dodai > t2.dodai)
            return true;
        return false;
    }    
};

priority_queue <campus, vector <campus>, sosanh > pq;
toado p[800];
double a[800][800];
int d[800],tree[800];
int n;
/**/
double kc(int i,int j)
{
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
/**/
void solve()
{
    campus nut;
    int i;
    double len;
    int dem;
    
    len = 0;
    dem = 0;
    tree[dem++] = 1;
    
    while(!pq.empty())
        pq.pop();
    
    for(i=2;i<=n;i++)
    {
        nut.dau = 1;
        nut.cuoi = i;
        nut.dodai = a[1][i];
        pq.push(nut);
    }
    d[1] = 1;
    while(dem != n)
    {
        while(!pq.empty())
        {
            nut = pq.top();
            pq.pop();
            if(!d[nut.cuoi])
            {
                tree[dem++] = nut.cuoi;
                d[nut.cuoi] = 1;
                len += nut.dodai;
                break;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(d[i] == 0)
            {
                nut.dau = tree[dem-1];
                nut.cuoi = i;
                nut.dodai = a[nut.dau][nut.cuoi];
                pq.push(nut);
            }
        }
    }
    
    printf("%0.2lf\n",len);
}
/**/
void input()
{
    int i,j;
    int m;
    int x,y;
    while(scanf("%d",&n) == 1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            for(j=i-1;j>0;j--)
                a[i][j] = a[j][i] = kc(i,j);
            d[i] = 0;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = a[y][x] = 0;
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
