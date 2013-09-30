/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
//#include <map>

#define fi "109.inp"
#define fo "109.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;   
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
toado ch[110][1000];
int len[110];
vector<toado > p;
priority_queue<toado, vector<toado >, sosanh > pq;
bool d[110];
int n;
/**/
double ccw(toado t1,toado t2,toado t3)
{
    return ((t2.x - t1.x) * (t3.y - t1.y) - (t2.y - t1.y) * (t3.x - t1.x));
}
/**/
bool chk_in(toado a,int id)
{
    int i;
    for(i=0;i<len[id]-1;i++)
        if(ccw(a,ch[id][i],ch[id][i+1]) < 0)
            return false;
    return true;
}
/**/
void convexh(int id)
{
    int i,k;
    int siz;
    
    siz = p.size();
    
    for(i=0;i<siz;i++)
    {
        while(len[id] >= 2 && ccw(ch[id][len[id]-2],ch[id][len[id]-1],p[i]) < 0)
            len[id]--;
        ch[id][len[id]++] = p[i];
    }
    
    k = len[id]+1;
    
    for(i=siz-2;i>=0;i--)
    {
        while(len[id] >= k && ccw(ch[id][len[id]-2],ch[id][len[id]-1],p[i]) <= 0)
            len[id]--;
        ch[id][len[id]++] = p[i];
    }
}
/**/
double dt(int id)
{
    int i;
    double s;
    
    s = 0;
    for(i=1;i<len[id]-1;i++)
        s += ccw(ch[id][0],ch[id][i],ch[id][i+1]);
        
    s = fabs(s);
    s = s / 2.0;
    
    return s;
}
/**/
void input()
{
    int i;
    int m;
    toado t;
    double s;
    
    n = 0;
        
    while(scanf("%d",&m) && m != -1)
    {
        for(i=0;i<m;i++)    
        {
            scanf("%d %d",&t.x,&t.y);
            pq.push(t);
        }
        
        p.clear();
        len[n] = 0;
        
        d[n] = true;
        
        while(!pq.empty())
        {
            p.push_back(pq.top());    
            pq.pop();
        }
        
        convexh(n);
        
        n++;
    }
    
    s = 0;
    while(scanf("%d %d",&t.x,&t.y) == 2)
    {
        for(i=0;i<n;i++)
            if(d[i] && chk_in(t,i))
            {
                d[i] = false;
                s += dt(i);
            }
    }
    printf("%0.2lf\n",s);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    input();

    return 0;
}
