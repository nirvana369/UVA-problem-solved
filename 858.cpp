/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "858.inp"
#define fo "858.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
class sosanh{
public:
    bool operator()(toado g1,toado g2)
    {
        if(g1.x > g2.x)
            return true;
        else if(g1.x == g2.x)
            if(g1.y > g2.y)
                return true;
        return false;
    }
};
priority_queue<toado, vector<toado > , sosanh > pq;
toado p[10010];
toado p1,p2;
double a,b,c,len;
int n;
/**/
double dist(toado g1,toado g2)
{
    return sqrt((g1.x-g2.x) * (g1.x-g2.x) + (g1.y-g2.y) * (g1.y-g2.y));
}
/**/
void chk(toado g1,toado g2)
{
    double minx,maxx;
    double a1,b1,c1;
    double dx,dy,d;
    toado t;
    
    a1 = g1.y - g2.y;
    b1 = g2.x - g1.x;
    c1 = -(g1.x * a1 + g1.y * b1);
    
    d = a * b1 - a1 * b;
    dx = b * c1 - b1 * c;
    dy = c * a1 - c1 * a;
    
    t.x = dx / d;
    t.y = dy / d;
    
    if((t.x - g1.x) * (t.x - g2.x) > 0 || (t.y - g1.y) * (t.y - g2.y) > 0)
        return;
    pq.push(t);
}
/**/
void solve()
{
    int i,k,j;
    double l;

    while(!pq.empty())
        pq.pop();
        
    p[n] = p[0];
    p2.x = p1.x;
    p1.y = 0;

    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -(p1.x * a + p1.y * b);    
    
    for(i=1;i<=n;i++)
        chk(p[i-1],p[i]);

    l = 0;
    i = 0;
    while(!pq.empty())
    {
        p[i] = pq.top();
        pq.pop();
        if(i % 2 != 0)
            l += dist(p[i],p[i-1]);
        i++;
    }
    if(l >= len)
        printf("YES\n");
    else
        printf("NO\n");
}
/**/
void input()
{
    int i;
    int ntest;
    toado t;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
            if(i)
                p2.y = p[i].y > p2.y ? p[i].y : p2.y;
            else
                p2.y = p[i].y;
        }
            
        scanf("%lf %lf",&len,&p1.x);
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
