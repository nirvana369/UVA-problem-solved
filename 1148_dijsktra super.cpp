/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <iostream>

#define fi "1148.inp"
#define fo "1148.out"
/**/
using namespace std;
/**/
struct mys{
                long tt;
                long val;
            };
            
class sosanh{
public:
    bool operator()(mys t1,mys t2)
    {
        if(t1.val > t2.val)
            return true;
        return false;
    }
};
vector<long > a[100100];
priority_queue<mys, vector<mys>, sosanh > pq;
bool d[100100];
long nhan[100100];
long n;
/**/
void solve()
{
    long io,i;
    long xp,kt;
    mys t,tmp;
    
    while(!pq.empty())
        pq.pop();
    scanf("%ld %ld",&xp,&kt);
    t.tt = xp;
    t.val = 0;
    nhan[xp] = 0;
    pq.push(t);
    
    while(!pq.empty())
    {
        while(!pq.empty())
        {
            t = pq.top();
            pq.pop();
            if(d[t.tt])
                break;
        }
        if(t.tt == kt)
            break;
        d[t.tt] = false;
        for(i=0;i<a[t.tt].size();i++)
            if(nhan[t.tt] + 1 < nhan[a[t.tt][i]])
            {
                nhan[a[t.tt][i]] = nhan[t.tt] + 1;
                tmp.tt = a[t.tt][i];
                if(d[tmp.tt])
                {
                    tmp.val = nhan[a[t.tt][i]];
                    pq.push(tmp);
                }
            }
    }
    printf("%ld %ld %ld\n",xp,kt,nhan[kt]-1);
}
/**/
void input()
{
    long i,j;
    long m,x,y;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            d[i] = true;
            nhan[i] = 32000;
            
            scanf("%ld %ld",&x,&m);
            a[x].clear();
            for(j=0;j<m;j++)
            {
                scanf("%ld",&y);
                a[x].push_back(y);
            }
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
