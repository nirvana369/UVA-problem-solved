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

#define fi "11747.inp"
#define fo "11747.out"
/**/
using namespace std;
/**/
struct way{
                int x,y;
                long len;
                };
class sosanh{
public:
    bool operator()(way t1, way t2)
    {
        if(t1.len > t2.len)
            return true;
        return false;
    }    
};
priority_queue <way, vector<way>, sosanh> pq;
int d[1100] ,truoc[1100];
int n,m;
/**/
int fpre(int nut)
{
    while(nut != truoc[nut])
        nut = truoc[nut];
    return nut;
}
/**/
void solve()
{
    way tg;
    bool fst;
    int nut1,nut2;
    fst = true;
    while(!pq.empty())
    {
        tg = pq.top();
        pq.pop();
        if(d[tg.x] && d[tg.y])
        {
            d[tg.x] = d[tg.y] = 0;
            truoc[tg.y] = tg.x;
        }
        else if(d[tg.x])
        {
            truoc[tg.x] = fpre(tg.y);
            d[tg.x] = 0;
        }
        else if(d[tg.y])
        {
            truoc[tg.y] = fpre(tg.x);
            d[tg.y] = 0;
        }
        else
        {
            nut1 = fpre(tg.x);
            nut2 = fpre(tg.y);
            if(nut1 != nut2)
                truoc[nut2] = nut1;
            else
            {
                truoc[tg.x] = nut1;
                truoc[tg.y] = nut2;
                if(fst)
                {
                    printf("%ld",tg.len);
                    fst = false;
                }
                else
                    printf(" %ld",tg.len);
            }
        }
    }
    if(fst)
        printf("forest");
    printf("\n");
}
/**/
void khoitao()
{
    int i;
    while(!pq.empty())
        pq.pop();
    for(i=0;i<n;i++)
    {
        d[i] = 1;
        truoc[i] = i;
    }
}
/**/
void input()
{
    int i;
    way tg;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %ld",&tg.x,&tg.y,&tg.len);
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
