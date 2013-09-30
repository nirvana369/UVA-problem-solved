/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10382.inp"
#define fo "10382.out"
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
        return false;
    }
};
priority_queue <toado , vector<toado>, sosanh > pq;
toado k[10100];
int n,l,w;
/**/
void solve()
{
    toado t;
    int i;
    int vt,dem,sp,temp;
    double dau,cuoi;
    bool timthay;
    
    dem = 0;
       
    while(!pq.empty())
    {
        k[dem++] = pq.top();
        pq.pop();
    }
    
    vt = 0;
    sp = 0;
    
    dau = 0;
    cuoi = 0;
    while(true)
    {
        timthay = false;
        for(i=vt;i<dem;i++)
            if(k[i].x <= dau)
            {
                if(k[i].y > cuoi)
                {
                    cuoi = k[i].y;
                    vt = i+1;
                    timthay = true;
                }
            }
            else
                break;
        
        dau = cuoi;
        sp++;
        
        if(!timthay || cuoi >= l)
            break;
    }
    
    if(cuoi >= l)
        printf("%d\n",sp);
    else
        printf("-1\n");
}
/**/
void input()
{
    toado t;
    double kc,temp,tg;
    int i;
    int pos,r;
    while(scanf("%d %d %d",&n,&l,&w) == 3)
    {
        while(!pq.empty())
            pq.pop();
        tg = (double)w / 2;
        tg *= tg;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&pos,&r);
            temp = (double)r * r - tg;
            if(temp < 0)
                temp = -temp;
            kc = sqrt(temp);
            t.x = (double)pos - kc;
            t.y = (double)pos + kc;
            if(r*2 >= w)
                pq.push(t);
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

