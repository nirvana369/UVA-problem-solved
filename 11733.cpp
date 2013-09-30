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

#define fi "11733.inp"
#define fo "11733.out"
/**/
using namespace std;
/**/
struct way{
                int x,y;
                int len;
            };
class sosanh{
public:
    bool operator()(way t1,way t2)
    {
        if(t1.len > t2.len)
            return true;
        return false;
    }
};
priority_queue <way, vector<way>, sosanh > pq;
int d[10100],d_area[10100],truoc[10100];
int n;
long val;
long long dodai;
/**/
int fpre(int nut)
{
    while(nut != truoc[nut])
        nut = truoc[nut];
    return nut;
}
/**/
void demvung()
{
    int i;
    int nut,dem;
    dem = 0;
    for(i=1;i<=n;i++)           // count area
    {
        nut = fpre(i);
        if(d_area[nut])
        {
            d_area[nut] = 0;
            dem++;
        }
    }
    dodai += dem * val;  // min cost and max airpost
    printf("%lld %d\n",dodai,dem);
}
/**/
void solve()
{
    way tg;
    int nut1,nut2;
    
    while(!pq.empty())
    {
        tg = pq.top();
        pq.pop();
        if(d[tg.x] && d[tg.y])
        {
            d[tg.x] = d[tg.y] = 0;
            if(tg.len < val)        // if cost build airpost > cost build road
            {
                truoc[tg.y] = tg.x; // add to area
                dodai += tg.len;    
            }
        }
        else if(d[tg.x])
        {
            d[tg.x] = 0;
            if(tg.len < val)
            {
                nut1 = fpre(tg.y);
                truoc[tg.x] = nut1;
                dodai += tg.len;
            }
        }
        else if(d[tg.y])
        {
            d[tg.y] = 0;
            if(tg.len < val)
            {
                nut1 = fpre(tg.x);
                truoc[tg.y] = nut1;
                dodai += tg.len;
            }
        }
        else
        {
            nut1 = fpre(tg.x);
            nut2 = fpre(tg.y);
            if(nut1 != nut2)
            {
                if(tg.len < val)
                {
                    truoc[nut2] = nut1;
                    dodai += tg.len;
                }
            }
            else
            {
                truoc[tg.x] = nut1;
                truoc[tg.y] = nut2;
            }
        }
    }
    
    demvung();
}
/**/
void khoitao()
{
    int i;
    while(!pq.empty())
        pq.pop();
        
    for(i=1;i<=n;i++)
    {
        d[i] = 1;
        d_area[i] = 1;
        truoc[i] = i;
    }
    dodai = 0;
}
/**/
void input()
{
    long i,nroad;
    way tg;
    int ntest,id;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %ld %d",&n,&nroad,&val);
        khoitao();
        for(i=0;i<nroad;i++)
        {
            scanf("%d %d %d",&tg.x,&tg.y,&tg.len);
            pq.push(tg);
        }
        printf("Case #%d: ",id++);
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
