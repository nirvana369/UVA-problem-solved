/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "1216.inp"
#define fo "1216.out"
/**/
using namespace std;
/**/
struct race{
                long x,y;
                double c;
            };
            
class sosanh{
public:
    bool operator()(race t1,race t2)
    {
        if(t1.c > t2.c)
            return true;
        return false;
    }    
};
race pos[10100];
bool d[10100];
int pre[10100];
priority_queue<race, vector<race> , sosanh > pq;
int n;
long m,sum;
/**/
void khoitao()
{
    long i;
    for(i=1;i<m;i++)
        pre[i] = i;
}
/**/
int fpre(int v)
{
    while(v != pre[v])
        v = pre[v];
    return v;
}
/**/
double kc(race a,race b)
{
    double tmpa,tmpb;
    tmpa = pow((a.x-b.x),2);
    tmpb = pow((a.y-b.y),2);
    tmpa = pow(tmpa + tmpb,0.5);
    return tmpa;
}
/**/
void solve()
{
    race t;
    int ne,u,v;
    khoitao();
    ne = m-1;
    while(ne != n)
    {
        t = pq.top();
        pq.pop();
        u = fpre(t.x);
        v = fpre(t.y);
        if(u != v)
        {
            pre[v] = u;
            pre[t.x] = u;
            pre[t.y] = u;
            ne--;
        }
        if(ne == n)
        {
            printf("%.lf\n",ceil(t.c));
            return;
        }
        if(pq.empty())
            break;
    }
    printf("%lf\n",ceil(t.c));
}
/**/
void input()
{
    long i;
    int ntest;
    race t;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        while(!pq.empty())
            pq.pop();
        m = 1;
        while(scanf("%ld",&pos[m].x) == 1)
        {
            if(pos[m].x == -1)
                break;
            scanf("%ld",&pos[m].y);
            t.x = m;
            for(i=m-1;i>0;i--)
            {
                t.y = i;
                t.c = kc(pos[m],pos[i]);
                pq.push(t);
            }
            m++;
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
