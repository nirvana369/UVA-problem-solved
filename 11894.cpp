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

#define fi "11894.inp"
#define fo "11894.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
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
toado p[100010],a[100010],p1[100010];
priority_queue<toado , vector<toado > , sosanh > pq;
long n;
/**/
void rot()
{
    long i;
    toado t;
    for(i=0;i<n;i++)
    {
        t.x = -a[i].y;
        t.y = a[i].x;
        pq.push(t);
    }
}
/**/
void tinhtien(toado pos[])
{
    long i;
    int px,py;
    px = pos[0].x;
    py = pos[0].y;
    
    for(i=0;i<n;i++)
    {
        pos[i].x -= px;
        pos[i].y -= py;
    }
}
/**/
bool solve()
{
    long i,j;
    bool match;

    tinhtien(p);

    i = 0;
    do
    {
        j = 0;
        while(!pq.empty())
        {
            a[j] = pq.top();
            p1[j] = a[j];
            j++;
            pq.pop();
        }
        tinhtien(p1);
        match = true;
        
        for(j=0;j<n;j++)
            if(p[j].x != p1[j].x || p[j].y != p1[j].y)
            {
                match = false;
                break;
            }
        if(match)        
            return true;
            
        rot();
        i++;
    }while(i < 4);
    
    return false;
}
/**/
void input()
{
    long i;
    int ntest;
    toado t;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        while(!pq.empty())
            pq.pop();
            
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&t.x,&t.y);
            pq.push(t);
        }
        i = 0;
        while(!pq.empty())
        {
            p[i++] = pq.top();
            pq.pop();
        }
    
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&t.x,&t.y);
            pq.push(t);
        }
        if(solve())
            printf("MATCHED\n");
        else
            printf("NOT MATCHED\n");
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
