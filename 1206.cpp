/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
//#include <map>

#define fi "1206.inp"
#define fo "1206.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
            
class sosanh{
public:
    bool operator()(toado t1 , toado t2)
    {
        if(t1.x > t2.x)
            return true;
        if(t1.x == t2.x)
            if(t1.y > t2.y)
                return true;
        return false;
    }    
};
toado a[100000],p[100000];
char s[1000000];
priority_queue<toado, vector<toado > , sosanh > pq;
/**/
double ccw(toado t1,toado t2,toado t3)
{
    return ((t2.x - t1.x) * (t3.y - t1.y) - (t3.x - t1.x) * (t2.y - t1.y));
}
/**/
void convex()
{
    long i,j,k;
    long tmp;
    long n;
    
    n = k = 0;
    
    while(!pq.empty())
    {
        a[n++] = pq.top();
        pq.pop();
    }
    
    for(i=0;i<n;i++)
    {
        while(k >= 2 && ccw(p[k-2],p[k-1],a[i]) <= 0)
            k--;
        p[k++] = a[i];
    }
    j = k + 1;
    
    for(i=n-2;i>=0;i--)
    {
        while(k >= j && ccw(p[k-2],p[k-1],a[i]) <= 0)
            k--;
        p[k++] = a[i];
    }
    
    for(i=0;i<k;i++)
    {
        if(i)
            printf(" ");
        printf("(%g,%g)",p[i].x,p[i].y);
    }
    printf("\n");
}
void input()
{
    string s;
    toado t;
    char ch;
    
    while(getline(cin,s)) 
    {
        stringstream sin(s);
        while(sin >> ch >> t.x >> ch >> t.y >> ch) 
            pq.push(t);
        convex();
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
