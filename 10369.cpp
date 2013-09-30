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

#define fi "10369.inp"
#define fo "10369.out"
/**/
using namespace std;
/**/
struct netw{
                int dau,cuoi;
                double len;
            };
struct toado{
                int x,y;
            };
class sosanh{
public:
    bool operator()(netw t1,netw t2)
    {
        if(t1.len > t2.len)
            return true;
        return false;
    }   
};
priority_queue <netw, vector<netw>, sosanh > pq,luu;
toado p[550];
netw kq[550];
int d[550];
double a[550][550];
int n,s;
/**/
double kc(int i,int j)
{
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
/**/
void solve()
{
    int i;
    int dem;
    double tong;
    netw tg;
    
    
    while(!pq.empty())
        pq.pop();
    while(!luu.empty())
        luu.pop();
        
    tg.dau = 0;
    d[0] = 1;
    for(i=0;i<n;i++)
        if(!d[i])
        {
            tg.cuoi = i;
            tg.len = a[0][i];
            pq.push(tg);
        }
    dem = 1;
    while(dem != n)
    {
        while(!pq.empty())
        {
            tg = pq.top();
            pq.pop();
            if(!d[tg.cuoi])
            {
                d[tg.cuoi] = 1;
                luu.push(tg);
                dem++;
                break;
            }
        }
        tg.dau = tg.cuoi;
        for(i=0;i<n;i++)
            if(!d[i])
            {
                tg.cuoi = i;
                tg.len = a[tg.dau][i];
                pq.push(tg);
            }
    }
    dem = 0;
    while(!luu.empty())
    {
        kq[dem++] = luu.top();
        luu.pop();
    }
    printf("%0.2lf\n",kq[dem-s].len);
}
/**/
void input()
{
    int i,j;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&s,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            for(j=i-1;j>=0;j--)
                a[i][j] = a[j][i] = kc(i,j);
            d[i] = 0;
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
