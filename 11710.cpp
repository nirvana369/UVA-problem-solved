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

#define fi "11710.inp"
#define fo "11710.out"
/**/
using namespace std;
/**/
struct way{
                long long len;
                int x,y;
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
map <string, int> mmap;
int d[410];
long long a[410][410];
int n,xp;
long nroad;
/**/
void solve()
{
    way tg;
    long long kq;
    int i,dem;
    bool noway;
    
    kq = 0;

    d[xp] = 0;
    tg.x = xp;
    for(i=1;i<=n;i++)
        if(d[i] && a[xp][i] != -1)
        {
            tg.y = i;
            tg.len = a[xp][i];
            pq.push(tg);
        }
    dem = 1;
    
    while(dem < n)
    {
        noway = true;
        while(!pq.empty())    
        {
            tg = pq.top();
            pq.pop();
            if(d[tg.y])
            {
                d[tg.y] = 0;
                dem++;
                kq += tg.len;
                noway = false;
                break;
            }
        }
        
        if(noway)
            break;
        
        tg.x = tg.y;
        for(i=1;i<=n;i++)
            if(d[i] && a[tg.x][i] != -1)
            {
                tg.y = i;
                tg.len = a[tg.x][i];
                pq.push(tg);
            }
    }
    
    if(dem < n)
        printf("Impossible\n");
    else
        printf("%lld\n",kq);
}
/**/
void khoitao()
{
    int i,j;
    
    mmap.clear();
    while(!pq.empty())
        pq.pop();
    for(i=1;i<=n;i++)    
    {
        for(j=i+1;j<=n;j++)
            a[i][j] = a[j][i] = -1;
        a[i][i] = -1;
    }
}
void input()
{
    char s1[100],s2[100];
    long i;
    way tg;
    
    while(true)
    {
        scanf("%d %ld",&n,&nroad);
        if(!n && !nroad)
            break;
        khoitao();
        for(i=1;i<=n;i++)
        {
            scanf("%s",&s1);
            mmap[s1] = i;
            d[i] = 1;
        }
        for(i=0;i<nroad;i++)
        {
            scanf("%s %s %lld",&s1,&s2,&tg.len);
            tg.x = mmap[s1];
            tg.y = mmap[s2];
            a[tg.x][tg.y] = a[tg.y][tg.x] = tg.len;
        }
        scanf("%s",&s1);
        xp = mmap[s1];
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
