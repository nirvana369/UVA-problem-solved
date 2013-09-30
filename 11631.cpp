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

#define fi "11631.inp"
#define fo "11631.out"
/**/
using namespace std;
/**/
struct road{
                long x,y;
                long val;
            };
class sosanh{
public:
    bool operator()(road t1,road t2)
    {
        if(t1.val > t2.val)
            return true;
        return false;
    }
};
priority_queue <road, vector<road>, sosanh > pq;
long len,n,m;
int d[200010];
long truoc[200010];
/**/
void khoitao()
{
    long i;
    while(!pq.empty())
        pq.pop();
    for(i=0;i<n;i++)
    {
        d[i] = 1;
        truoc[i] = i;
    }
    len = 0;
}
/**/
long findtruoc(long dinh)
{
    while(dinh != truoc[dinh])
        dinh = truoc[dinh];
    return dinh;
}
/**/
void solve()
{
    long gt;
    road tg;
    long dem;
    
    gt = 0;
    dem = 0;
    while(!pq.empty())
    {
        tg = pq.top();
        pq.pop();
        if(d[tg.x] && d[tg.y])
        {
            d[tg.x] = d[tg.y] = 0;
            dem += 2;
            truoc[tg.y] = tg.x;
            gt += tg.val;
        }
        else if(d[tg.x])
        {
            d[tg.x] = 0;
            truoc[tg.x] = findtruoc(tg.y);
            dem++;
            gt += tg.val;
        }
        else if(d[tg.y])
        {
            d[tg.y] = 0;
            truoc[tg.y] = findtruoc(tg.x);
            dem++;
            gt += tg.val;
        }
        else
        {
            tg.x = findtruoc(tg.x);
            tg.y = findtruoc(tg.y);
            if(tg.x != tg.y)
            {
                truoc[tg.y] = tg.x;
                gt += tg.val;
            }
        }
    }
    printf("%ld\n",len-gt);
}
/**/
void input()
{
    long i;
    road tg;
    while(scanf("%ld %ld",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %ld",&tg.x,&tg.y,&tg.val);
            len += tg.val;
            pq.push(tg);
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
