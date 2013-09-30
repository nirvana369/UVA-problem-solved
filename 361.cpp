/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "361.inp"
#define fo "361.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
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
priority_queue<toado, vector<toado > , sosanh > pq;
toado c[250];
double a1,b1,c1,a2,c2,b2,d,dx,dy;
/**/
double ccw(toado a,toado b,toado c)
{
    return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
/**/
int convex(toado a[],int n,toado cvh[])
{
    int i,j,k;
    
    k = 0;
    
    for(i=0;i<n;i++)
    {
        while(k >= 2 && ccw(cvh[k-2],cvh[k-1],a[i]) <= 0)
            k--;
        cvh[k++] = a[i];
    }
    
    for(i=n-2,j=k+1;i>=0;i--)
    {
        while(k >= j && ccw(cvh[k-2],cvh[k-1],a[i]) <= 0)
            k--;
        cvh[k++] = a[i];
    }
    
    return k;
}
/**/
bool thesame(toado a,toado b)
{
    if(a.x != b.x || a.y != b.y)
        return false;
    return true;
}
/**/
int chk(int n,toado p[],toado m,toado m1)
{
    int i;
    int dem;
    toado p1,p2;
    
    dem = 0;
        
    for(i=0;i<n-1;i++)
    {
        a1 = p[i].y - p[i+1].y;
        b1 = p[i+1].x - p[i].x;
        c1 = -(a1 * p[i].x + b1 * p[i].y);
        ///
        
        d = a1 * b2 - a2 * b1;
        dx = b1 * c2 - b2 * c1;
        dy = c1 * a2 - c2 * a1;
        
        if(d != 0)
        {
            dx /= d;
            dy /= d;
            if((dx - p[i].x) * (dx - p[i+1].x) <= 0 && (dy - p[i].y) * (dy - p[i+1].y) <= 0)        
            {
                dem++;
                if(dem == 1)
                {
                    p1.x = dx;
                    p1.y = dy;
                }
                else
                {
                    p2.x = dx;
                    p2.y = dy;
                }
            }
        }
    }
    if(dem > 2)
        return 0;
    if(dem == 2)
    {
        if((m.x - p1.x) * (m.x - p2.x) > 0 || (m.y - p1.y) * (m.y - p2.y) > 0)
            return 2;
        return 1;
    }
    return dem;
}
/**/
bool checkin(int n,toado p[],toado m)
{
    int i;
    int tmp;
    toado m1;
    
    for(i=0;i<n;i++)
        if(thesame(m,p[i]))
            return true;
    
    for(i=0;i<n-1;i++)
    {
        a1 = p[i].y - p[i+1].y;
        b1 = p[i+1].x - p[i].x;
        c1 = -(a1 * p[i].x + b1 * p[i].y);
        
        m1.x = (p[i].x + p[i+1].x) / 2;
        m1.y = (p[i].y + p[i+1].y) / 2;
        
        a2 = m.y - m1.y;
        b2 = m1.x - m.x;
        c2 = -(a2 * m.x + b2 * m.y);
        
        d = a1 * b2 - a2 * b1;
        dx = b1 * c2 - b2 * c1;
        dy = c1 * a2 - c2 * a1;
        if(d == 0 && (m.x - p[i].x) * (m.x - p[i+1].x) <= 0 && (m.y - p[i].y) * (m.y - p[i+1].y) <= 0)
            return true;
        if(d != 0)
        {
            tmp = chk(n,p,m,m1);
            if(tmp)
            {
                if(tmp % 2 != 0)
                    return true;
                return false;
            }
        }
    }
    return false;
}
/**/
void input()
{
    int i;
    int id;
    int nc,nr,np,cvrop,cvcop;
    toado cop[250],rop[250];
    toado t;
    id = 1;
    
    while(scanf("%d %d %d",&nc,&nr,&np))
    {
        if(!nc && !nr && !np)
            break;
            
        while(!pq.empty())
            pq.pop();
        // input cop
        for(i=0;i<nc;i++)
        {
            scanf("%lf %lf",&t.x,&t.y);
            pq.push(t);
        }
        i = 0;
        while(!pq.empty())
        {
            c[i++] = pq.top();
            pq.pop();
        }
        if(nc)
            cvcop = convex(c,nc,cop);
        // input rop
        for(i=0;i<nr;i++)
        {
            scanf("%lf %lf",&t.x,&t.y);
            pq.push(t);
        }
        i = 0;
        while(!pq.empty())
        {
            c[i++] = pq.top();
            pq.pop();
        }
        cvrop = convex(c,nr,rop);
        
        printf("Data set %d:\n",id++);
        while(np--)
        {
            scanf("%lf %lf",&t.x,&t.y);
            printf("     Citizen at (%.lf,%.lf) ",t.x,t.y);
            if(nc > 2 && checkin(cvcop,cop,t))
                printf("is safe.\n");
            else if(nr > 2 && checkin(cvrop,rop,t))   
                printf("is robbed.\n");
            else
                printf("is neither.\n");
        }
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
