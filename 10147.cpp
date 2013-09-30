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

#define fi "10147.inp"
#define fo "10147.out"
#define maxgt 300000000l
/**/
using namespace std;
/**/
struct hw{
            int dau,cuoi;
            long len;
         };
struct toado{
                int x,y;
            };
class sosanh{
public:
    bool operator()(hw t1,hw t2)
    {
        if(t1.len > t2.len)
            return true;
        return false;
    }
    };
priority_queue <hw, vector <hw>, sosanh> pq;
toado p[800];
long a[800][800];
int d[800],tree[800];
int n,dinh;
/**/
long kc(int i,int j)
{
    return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
}
/**/
void solve()
{
    hw data;
    int i,j;
    int vt,xp;
    bool dinham;
    long temp;
    
    dinh = 0;
    tree[dinh++] = 1;
    d[1] = 1;
    dinham = true;
    
    while(!pq.empty())
        pq.pop();
    
    for(i=2;i<=n;i++)
    {
        data.dau = 1;
        data.cuoi = i;
        data.len = a[1][i];
        pq.push(data);
    }
    while(dinh != n)
    {
        temp = maxgt;
        vt = -1;
        while(!pq.empty())
        {
            data = pq.top();
            pq.pop();
            if(!d[data.cuoi])
            {
                xp = data.dau;
                vt = data.cuoi;
                break;
            }
        }
                        
        if(a[xp][vt] != -1)
        {
            printf("%d %d\n",xp,vt);
            dinham = false;
        }
        tree[dinh++] = vt;
            d[vt] = 1;
        for(i=1;i<=n;i++)
            if(d[i] == 0)
            {
                data.dau = vt;
                data.cuoi = i;
                data.len = a[vt][i];
                pq.push(data);
            }
    }
    if(dinham)
        printf("No new highways need\n");
}
/**/
void input()
{
    int ntest;
    int x,y,m;
    int i,j;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
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
            a[x][y] = a[y][x] = -1;
        }
        solve();
        if(ntest)
            printf("\n");
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
