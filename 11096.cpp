/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "11096.inp"
#define fo "11096.out"
/**/
using namespace std;
/**/
struct toado{
                long x,y;
            };
class sosanh{
public:
    bool operator()(toado a,toado b)
    {
        if(a.x > b.x)
            return true;
        if(a.x == b.x)
            if(a.y > b.y)
                return true;
        return false;
    }
};
priority_queue<toado, vector<toado>, sosanh > pq;
toado p[110],cvh[110];
double flen;
int n;
/**/
double ccw(toado p1,toado p2,toado p3)
{
    return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}
/**/
double dist(toado a,toado b)
{
    double x = pow(a.x - b.x , (double) 2);
    double y = pow(a.y - b.y , (double) 2);

    return pow(x+y,(double)0.5);
}
/**/
void solve()
{
    int i,j,k;
    double len;
       
    n = 0;
    while(!pq.empty())
    {
        p[n++] = pq.top();
        pq.pop();
    }
    k = 0;
    for(i=0;i<n;i++)
    {
        while(k >= 2 && ccw(cvh[k-2],cvh[k-1],p[i]) <= 0)
            k--;
        cvh[k++] = p[i];
    }
    
    for(i=n-2,j=k+1;i>=0;i--)
    {
        while(k >= j && ccw(cvh[k-2],cvh[k-1],p[i]) <= 0)
            k--;
        cvh[k++] = p[i];
    }
    
    len = 0;
    for(i=0;i<k-1;i++)    
        len += dist(cvh[i],cvh[i+1]);
        
    if(len < flen)
        len = flen;
    printf("%0.5lf\n",len);
}
/**/
void input()
{
    int i;
    int ntest;
    toado pos;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lf %d",&flen,&n);
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld",&pos.x,&pos.y);
            pq.push(pos);
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
