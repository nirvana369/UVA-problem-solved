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

#define fi "596.inp"
#define fo "596.out"
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
        if(t1.x < t2.x)
            return true;
        if(t1.x == t2.x)
            if(t1.y > t2.y)
                return true;
        return false;
    }    
};
toado a[600],p[600];
priority_queue<toado, vector<toado > , sosanh > pq;
int n;
/**/
double ccw(toado t1,toado t2,toado t3)
{
    return ((t2.x - t1.x) * (t3.y - t1.y) - (t2.y - t1.y) * (t3.x - t1.x));
}
/**/
bool dif(toado t1,toado t2)
{
    if(t1.x != t2.x || t1.y != t2.y)
        return true;
    return false;
}
/**/
void solve()
{
    int i,j,k;
    int id;
    toado t;
    
    n = 0;
    a[n++] = pq.top();
    pq.pop();
    while(!pq.empty())
    {
        t = pq.top();
        if(dif(t,a[n-1]))
            a[n++] = t;
        pq.pop();
    }
    
    k = 0;
    for(i=0;i<n;i++)
    {
        while(k >= 2 && ccw(p[k-2],p[k-1],a[i]) < 0)
            k--;
        p[k++] = a[i];
    }
    
    j = k + 1;
    
    for(i=n-2;i>=0;i--)
    {
        while(k >= j && ccw(p[k-2],p[k-1],a[i]) < 0)
            k--;
        p[k++] = a[i];
    }
    
    k--;
    for(i=0;i<k;i++)
        printf(" (%d,%d)" ,p[i].x,p[i].y);
    printf("\n");
}
/**/
void xuly(char s[]) // hiem vai ca dai xu ly input
{
    int i,j;
    
    i = 0;
    
    while(s[i])
    {
        if(s[i] != ' ')
            break;
        i++;
    }
    j = 0;
    
    while(s[i])
        s[j++] = s[i++];
    s[j] = 0;
}
/**/
void input()
{
    char s[1000],tmp[1000];
    toado t;
    int i,id;
    
    scanf("%s",&s);
    while(true)
    {
        gets(s);   // hiem vai ca dai xu ly input
        xuly(s);        // hiem vai ca dai xu ly input
        while(!pq.empty())  
            pq.pop();
        
        while(true)
        {
            scanf("%s",&tmp);    
            if(tmp[0] != 'P')
                break;
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d %d",&t.x,&t.y);
                pq.push(t);
            }
        }
        
        printf("%s convex hull:\n",s);
        
        solve();
        
        if(tmp[0] == 'E')
            break;
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
