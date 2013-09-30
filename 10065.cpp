/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
//#include <vector>
//#include <map>

#define fi "10065.inp"
#define fo "10065.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
class sosanh{
public:
    bool operator()(toado t1,toado t2)    
    {
        if(t1.x > t2.x)
            return true;
        if(t1.x == t2.x)
            if(t1.y > t2.y)
                return true;
        return false;
    }
};
priority_queue<toado, vector<toado>, sosanh > pq;
toado p[110],ch[110];
int n;
/**/
double ccw(toado a,toado b,toado c)
{
    return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
/**/
void solve()
{
    int i,k,j;
    double ratio,s,sconvex;
    
    
    s = 0;
    for(i=1;i<n-1;i++)
        s += ccw(p[0],p[i],p[i+1]);
        
    s = fabs(0.5 * s);
    
    for(i=0;i<n;i++)
        pq.push(p[i]);
        
    n = 0;
    
    while(!pq.empty())
    {
        p[n++] = pq.top();
        pq.pop();
    }
    
    // convexhull
    k = 0;
    
    for(i=0;i<n;i++)
    {
        while(k >= 2 && ccw(ch[k-2],ch[k-1],p[i]) <= 0)
            k--;
        ch[k++] = p[i];
    }
    
    j = k + 1;
    
    for(i=n-2;i>=0;i--)
    {
        while(k >= j && ccw(ch[k-2],ch[k-1],p[i]) <= 0)
            k--;
        ch[k++] = p[i];
    }
    
    sconvex = 0;
    
    for(i=1;i<k-2;i++)
        sconvex += ccw(ch[0],ch[i],ch[i+1]);
    sconvex = fabs(0.5 * sconvex);
    
    ratio = (1 - s / sconvex) * 100;
    
    printf("Wasted Space = %0.2lf %%\n\n",ratio);
}
/**/
void input()
{
    int i,id;
    toado t;

    id = 1;    
    while(scanf("%d",&n) && n)
    {
        for(i = 0; i < n; i++)
            scanf("%lf %lf",&p[i].x, &p[i].y);
        printf("Tile #%d\n",id++);
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
