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
#include <vector>

#define fi "908.inp"
#define fo "908.out"
/**/
using namespace std;
/**/
struct cpt{
                long x,y;
                int val;
            };
class sosanh{
public:
    bool operator()(cpt t1,cpt t2)
    {
        if(t1.val > t2.val)
            return true;
        return false;
    }    
};
cpt line[15];
priority_queue <cpt, vector<cpt>, sosanh > pq;
vector <pair<long, int> > a[1000100];
int d[100100];
long n,m;
int k;
/**/
long mst()
{
    cpt t;
    int i;
    long gt,dem;
    
    while(!pq.empty())
        pq.pop();
    
    d[1] = 1;
    t.x = 1;
    for(i=0;i!=a[1].size();i++)
    {
        if(!d[a[1][i].first])
        {
            t.y = a[1][i].first;
            t.val = a[1][i].second;
            pq.push(t);
        }
    }
    dem = 1;
    gt = 0;
    while(true)
    {
        while(!pq.empty())
        {
            t = pq.top();
            pq.pop();
            if(!d[t.y])
            {
                d[t.y] = 1;
                gt += t.val;
                dem++;
                break;
            }
        }
        if(dem == n)
            break;
        t.x = t.y;
        for(i=0;i!=a[t.x].size();i++)
            if(!d[a[t.x][i].first])
            {
                t.y = a[t.x][i].first;
                t.val = a[t.x][i].second;
                pq.push(t);
            }
    }
    return gt;
}
/**/
void addline()
{
    long i;
    for(i=1;i<=n;i++)
        d[i] = 0;
    for(i=0;i<k;i++)
    {
        a[line[i].x].push_back(make_pair(line[i].y,line[i].val));
        a[line[i].y].push_back(make_pair(line[i].x,line[i].val));
    }
}
/**/
void solve()
{
    long kq,kq1;
    
    kq = mst();
    addline();
    kq1 = mst();
    
    printf("%ld\n%ld\n",kq,kq1);
}
/**/
void khoitao()
{
    long i;
    for(i=1;i<=n;i++)
    {
        d[i] = 0;
        a[i].clear();
    }
}
/**/
void input()
{
    cpt t;
    long i,id;
    id = 0;
    while(scanf("%ld",&n) == 1)
    {
        khoitao();
        for(i=0;i<n-1;i++)
        {
            scanf("%ld %ld %d",&t.x,&t.y,&t.val);
            a[t.x].push_back(make_pair(t.y,t.val));
            a[t.y].push_back(make_pair(t.x,t.val));
        }
        scanf("%d",&k);
        for(i=0;i<k;i++)
            scanf("%ld %ld %d",&line[i].x,&line[i].y,&line[i].val);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %d",&t.x,&t.y,&t.val);
            a[t.x].push_back(make_pair(t.y,t.val));
            a[t.y].push_back(make_pair(t.x,t.val));
        }
        if(id)
            printf("\n");
        solve();
        id++;
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
