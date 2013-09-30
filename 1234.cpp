/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iostream>

#define fi "1234.inp"
#define fo "1234.out"
/**/
using namespace std;
/**/
struct race{
                int x,y;
                long c;
            };
            
class sosanh{
public:
    bool operator()(race t1,race t2)
    {
        if(t1.c < t2.c)
            return true;
        return false;
    }    
};
bool d[10100];
vector<pair<int, long > > a[10100];
priority_queue<race, vector<race> , sosanh > pq;
int n;
long m,sum;
/**/
void khoitao()
{
    int i;
    
    for(i=1;i<=n;i++)
    {
        d[i] = true;
        a[i].clear();
    }
    sum = 0;
}
/**/
void solve()
{
    int i;
    race t;
    int dem;
    
    while(!pq.empty())
        pq.pop();
    
    t.x = 1;
    d[1] = false;
    for(i=0;i<a[t.x].size();i++)
    {
        if(d[a[t.x][i].first])
        {
            t.y = a[t.x][i].first;
            t.c = a[t.x][i].second;
            pq.push(t);
        }
    }
    
    dem = 1;
    while(dem < n)
    {
        while(!pq.empty())
        {
            t = pq.top();
            pq.pop();
            if(d[t.y])
            {
                sum -= t.c;
                t.x = t.y;
                d[t.x] = false;
                dem++;
                break;
            }
        }
        if(dem == n)
            break;
        
        for(i=0;i<a[t.x].size();i++)
        {
            if(d[a[t.x][i].first])
            {
                t.y = a[t.x][i].first;
                t.c = a[t.x][i].second;
                pq.push(t);
            }
        }
    }
    printf("%ld\n",sum);
}
/**/
void input()
{
    long i;
    int ntest;
    int x,y;
    long z;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %ld",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d %ld",&x,&y,&z);
            sum += z;            
            a[x].push_back(make_pair(y,z));
            a[y].push_back(make_pair(x,z));
        }
        solve();
    }
    scanf("%d",&x);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
