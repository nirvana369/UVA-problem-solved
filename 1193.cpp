/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "1193.inp"
#define fo "1193.out"
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
priority_queue<toado, vector<toado >, sosanh > pq;
toado p[1100];
int n,rd,d;
/**/
void solve()
{
    int i,j;
    double c,a,x,y,minr;
    int tmp;
    
    i = 0;
    while(!pq.empty())
    {
        p[i++] = pq.top();
        pq.pop();
    }
    c = d * d;    
    y = 0;
    
    minr = 0;
    for(i=0;i<n;i++)
    {
        a = p[i].y * p[i].y;
        x = sqrt(c-a) +1e-8;  // a2 + b2 = c2

        p[i].y = p[i].x + x;
        p[i].x -= x;
        minr = minr < p[i].x ? minr : p[i].x;
    }
    minr -= 1;
    i = 0;
    while(i < n) 
    {
        while(i < n && p[i].x <= minr)
        {
            minr = min(minr, p[i].y);
            i++;
        }
        minr = p[i].y;
        rd++;
    }
    
    printf("%d\n",rd-1);
}
/**/
int _abs(int val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
void input()
{
    int i,id;
    toado t;
    
    id = 1;
    while(scanf("%d %d",&n,&d))
    {
        if(!n && !d)
            break;
        while(!pq.empty())
            pq.pop();
        rd = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&t.x,&t.y);
            if(_abs((int)t.y) > d)
                rd = -1;
            if(rd >= 0)
                pq.push(t);
        }
        printf("Case %d: ",id++);
        if(rd < 0)
            printf("%d\n",rd);
        else
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
