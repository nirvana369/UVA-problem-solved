/*
                                                        Hoang Linh
                                                        
        convex hull algorithm : Monotone chain
        O(n log n) time
        
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "11626.inp"
#define fo "11626.out"
/**/
using namespace std;
/**/
struct toado{
                long x,y;
            };

// Sort points lexicographically uses priority queue
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
toado p[100010],kq[100010];
long n,m,xp;
/**/
/**/
// 2D cross product of ab and ac vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
double ccw(toado a,toado b,toado c)
{
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}
/**/
void solve()
{
    long i,j,k;
    
    n = 0;
    while(!pq.empty())
    {
        p[n++] = pq.top();
        pq.pop();
    }
    
     // Build lower hull
    k = 0;
    for(i=0;i<n;i++) 
    {
        while (k >= 2 && ccw(kq[k-2],kq[k-1],p[i]) < 0) 
            k--;
        kq[k++] = p[i];
    }
    // Build upper hull
    for(i=n-2,j=k+1;i>=0;i--) 
    {
        while (k >= j && ccw(kq[k-2],kq[k-1],p[i]) < 0) 
            k--;
        kq[k++] = p[i];
    }
    // output 
    printf("%d\n",k-1);
    for(i=0;i<k-1;i++)
        printf("%ld %ld\n",kq[i].x,kq[i].y);
}
/**/
void input()
{
    long i;
    char s[3];
    int ntest;
    toado pos;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&m);
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %s",&pos.x,&pos.y,&s);
            if(s[0] == 'Y')
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
