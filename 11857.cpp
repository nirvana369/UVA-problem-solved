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

#define fi "11857.inp"
#define fo "11857.out"
/**/
using namespace std;
/**/
struct city{
                long long len;
                long long dau,cuoi;
            };
class sosanh{
public:
    bool operator()(city t1,city t2)
    {
        if(t1.len > t2.len)
            return true;
        return false;
    }    
};
priority_queue <city, vector<city>, sosanh > pq;
int d[1000110];
long long truoc[1000110],val[1000110];
long long n,m,kq;
/**/
void khoitao()
{
    long long i;
    for(i=0;i<n;i++)
    {
        d[i] = 1;
        truoc[i] = i;
    }
}
/**/
long long ff(long long nut)
{
    while(nut != truoc[nut])
        nut = truoc[nut];
    return nut;
}
/**/
bool kiemtra()
{
    long long nut;
    long long i;
    
    nut = ff(0);
    
    for(i=1;i<n;i++)
        if(ff(i) != nut)
            return true;
    return false;
}
/**/
void solve()
{
    long long i;
    city tg;
    long long dem;
    long long nut1,nut2,kq;
    
    for(i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&tg.dau,&tg.cuoi,&tg.len);
        pq.push(tg);
    }
    dem = 0;
    kq = -1;
    while(!pq.empty())
    {
        tg = pq.top();
        pq.pop();
        if(d[tg.dau] && d[tg.cuoi])
        {
            d[tg.dau] = d[tg.cuoi] = 0;
            truoc[tg.cuoi] = tg.dau;
            dem += 2;
            if(tg.len > kq)
                kq = tg.len;
        }
        else if(d[tg.dau])
        {
            d[tg.dau] = 0;
            truoc[tg.dau] = ff(tg.cuoi);
            dem++;
            if(tg.len > kq)
                kq = tg.len;
        }
        else if(d[tg.cuoi])
        {
            d[tg.cuoi] = 0;
            truoc[tg.cuoi] = ff(tg.dau);
            dem++;
            if(tg.len > kq)
                kq = tg.len;
        }
        else
        {
            nut1 = ff(tg.dau);
            nut2 = ff(tg.cuoi);
            if(nut1 != nut2)
            {
                truoc[nut2] = nut1;
                if(tg.len > kq)
                    kq = tg.len;
            }
            else
            {
                truoc[tg.dau] = nut1;
                truoc[tg.cuoi] = nut2;
            }
        }
    } 
    
    if(kiemtra())
        printf("IMPOSSIBLE\n");
    else
        printf("%lld\n",kq);
}
/**/
void input()
{
    city tg;
    
    while(scanf("%lld %lld",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        khoitao();
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
