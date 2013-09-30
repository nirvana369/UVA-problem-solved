/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "10060.inp"
#define fo "10060.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
vector<toado > a;
/**/
double ccw(toado p1,toado p2,toado p3)
{
    return ((p2.x-p1.x) * (p3.y-p1.y) - (p2.y-p1.y) * (p3.x-p1.x));
}
/**/
double dientich()
{
    int i;
    double s;
    
    s = 0;
    
    for(i=0;i<a.size()-1;i++)
        s += ccw(a[0],a[i],a[i+1]);    
        
    s = fabs(s/2);
    
    return s;
}
/**/
void input()
{
    double pi,s,thick,r,tmh;
    long long ans;
    toado t;
    int n;
    
    pi = acos(-1);
    while(scanf("%d",&n) && n)
    {
        s = 0;
        while(n--)
        {
            a.clear();
            scanf("%lf %lf %lf",&thick,&t.x,&t.y);
            a.push_back(t);
            
            while(1)
            {
                scanf("%lf %lf",&t.x,&t.y);
                a.push_back(t);
                if(fabs(t.x-a[0].x) < 1e-8 && fabs(t.y-a[0].y) < 1e-8)
                    break;
            }
            s += dientich() * thick;
        }
        scanf("%lf %lf",&r,&tmh);

        ans = (long long)(s / (pi * r * r * tmh));

        printf("%lld\n",ans);
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
