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

#define fi "10462.inp"
#define fo "10462.out"
/**/
using namespace std;
/**/
struct way{
                int x,y;
                int val;
            };
class sosanh{
public:
    bool operator()(way g1,way g2)
    {
        if(g1.val > g2.val)        
            return true;
        return false;
    }
};
priority_queue <way, vector<way>, sosanh > pq;
way t[210],luu[110];
int t1[210],a[110][110],d[110];
int n,m,kq;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = 32000;
        d[i] = 0;
    }
}
/**/
int solve()
{
    int i;
    int dem;
    bool tim;
    way tg;
    int len;
    
    while(!pq.empty())
        pq.pop();
    
    len = 0;    
    dem = 1;
    tg.x = 1;
    d[1] = 1;
    for(i=1;i<=n;i++)
        if(!d[i] && a[1][i] != 32000)
        {
            tg.y = i;
            tg.val = a[1][i];
            pq.push(tg);
        }
    while(dem != n)
    {
        tim = false;
        while(!pq.empty())
        {
            tg = pq.top();
            pq.pop();
            if(!d[tg.y])
            {
                luu[dem++] = tg;
                d[tg.y] = 1;
                len += tg.val;
                tim = true;
                break;
            }
        }
        if(!tim)
            break;
        tg.x = tg.y;
        for(i=1;i<=n;i++)
            if(!d[i] && a[tg.x][i] != 32000)
            {
                tg.y = i;
                tg.val = a[tg.x][i];
                pq.push(tg);
            }
    }
    
    if(dem < n)
        return -1;
    return len;
}
/**/
bool kttrung(way i,way j)
{
    if(i.x == j.x && i.y == j.y && i.val == j.val)
        return true;
    if(i.x == j.y && i.y == j.x && i.val == j.val)
        return true;
    return false;
}
/**/
bool xuly()
{
    int i,j;
    int kq1,temp;
    bool disjoin;
    way luu1[110];
    
    for(i=1;i<n;i++)
        luu1[i] = luu[i];
    
    kq = 32000;
    for(i=1;i<n;i++)
    {
        khoitao();
        disjoin = false;
        for(j=0;j<m;j++)
        {
            if(!disjoin && kttrung(luu1[i],t[j]))
                disjoin = true;
            else
            {
                if(t[j].val < a[t[j].x][t[j].y])
                    a[t[j].x][t[j].y] = a[t[j].y][t[j].x] = t[j].val;
            }
        }
        kq1 = solve();
        if(kq1 != -1 && kq1 < kq)
            kq = kq1;
    }
    if(kq != 32000)
        return true;
    return false;
}
/**/
void input()
{
    int i;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&t[i].x,&t[i].y,&t[i].val);
            if(t[i].val < a[t[i].x][t[i].y])
                a[t[i].x][t[i].y] = a[t[i].y][t[i].x] = t[i].val;
        }
        printf("Case #%d : ",id++);
        kq = solve();
        if(kq == -1)
            printf("No way\n");
        else
        {
            if(!xuly())
                printf("No second way\n");
            else
                printf("%d\n",kq);
        }
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
