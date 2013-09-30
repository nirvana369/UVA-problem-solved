/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "453.inp"
#define fo "453.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y,r;
            };
toado t1,t2,p1,p2;
/**/
bool same(toado a,toado b)
{
    if(a.x != b.x || a.y != b.y || a.r != b.r)
        return false;
    return true;
}
/**/
double dist(double ax,double ay,double bx,double by)
{
    return sqrt((ax-bx) * (ax-bx) + (ay-by) * (ay-by));
}
/**/
void output()
{
    if(p1.x > p2.x)
        swap(p1,p2);
    else if(p1.x == p2.x)
        if(p1.y > p2.y)
            swap(p1,p2);
            
    printf("(%0.3lf,%0.3lf)(%0.3lf,%0.3lf)\n",p1.x,p1,p2.x,p2.y);
}
/**/
void solve()
{
    double kc,n1,n2,nr,delta;
    toado b1,b2,tmp;
    
    if(same(t1,t2))
    {
        printf("THE CIRCLES ARE THE SAME\n");
        return;
    }
    
    kc = dist(t1.x,t1.y,t2.x,t2.y);
    if(kc > t1.r + t2.r)
    {
        printf("NO INTERSECTION\n");
        return;
    }
    nr = t1.r;
    
    b1.x = 2 * t1.x;
    n1 = t1.x * t1.x;
    
    b1.y = 2 * t1.y;
    n1 += t1.y * t1.y;
    
    t1.r *= t1.r;
    
    b2.x = 2 * t2.x;
    n2 = t2.x * t2.x;
    
    b2.y = 2 * t2.y;
    n2 += t2.y * t2.y;
    
    t2.r *= t2.r;
    
    tmp.x = b1.x - b2.x;
    tmp.y = b1.y - b2.y;
    tmp.r = t1.r - t2.r;
    
    tmp.r -= (n1 - n2);
    
    if(fabs(tmp.x) < 1e-7)
    {
        p1.y = tmp.r / tmp.y;
        
        n1 = (t1.y - p1.y);
        n1 *= n1;
        n1 = nr - n1;
        n1 = -(t1.y * t1.y) - n1;
        delta = (b1.x * b1.x) - (4*n1);
        delta = pow(delta,0.5);
        
        p1.x = (-b1.x + delta) / 2;
        p2.y = p1.y;
        p2.x = (-b1.x - delta) / 2;
    }

    if(fabs(tmp.y) < 1e-7)
    {
        p1.x = tmp.r / tmp.x;
        
        n1 = (t1.x - p1.x);
        n1 *= n1;
        n1 = nr - n1;
        n1 = -(t1.x * t1.x) - n1;
        delta = (b1.y * b1.y) - (4*n1);
        delta = pow(delta,0.5);
        
        p1.y = (-b1.y + delta) / 2;
        p2.x = p1.x;
        p1.y = (-b1.y - delta) / 2;
    }
    
    if(dist(p1.x,p1.y,t1.x,t1.y) + dist(p1.x,p1.y,t1.x,t1.y) > kc)
    {
        printf("NO INTERSECTION\n");
        return;
    }
        
    output();
}
/**/
void input()
{
    while(scanf("%lf %lf %lf %lf %lf %lf",&t1.x,&t1.y,&t1.r,&t2.x,&t2.y,&t2.r) == 6)
    {
        if(t1.x < t2.x)
            swap(t1,t2);
        else if(t1.x == t2.x)
            if(t1.y < t2.y)
                swap(t1,t2);
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
