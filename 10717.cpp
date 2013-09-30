/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10717.inp"
#define fo "10717.out"
#define maxgt 2000000000l
/**/
using namespace std;
/**/
long c[100];
vector<long > leg;
int n,m;
/**/
long ucln(long a,long b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**/
long bcnn(long a,long b)
{
    return (a / ucln(a,b) * b);
}
/**/
void solve()
{
    int i,i1,i2,i3;
    
    leg.clear();
    for(i=0;i<n;i++)  // 4 leg
        for(i1=i+1;i1<n;i1++)
            for(i2=i1+1;i2<n;i2++)
                for(i3=i2+1;i3<n;i3++)
                    leg.push_back(bcnn(bcnn(bcnn(c[i],c[i1]),c[i2]),c[i3]));
}
/**/
void input()
{
    int i;
    long req,maxsize,minsize,tmp;
    
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
            
        for(i=0;i<n;i++)
            scanf("%ld",&c[i]);
        solve();
        while(m--)
        {
            scanf("%ld",&req);
            maxsize = 0;
            minsize = maxgt;
            for(i=0;i<leg.size();i++)
            {
                if(leg[i] <= req)
                {
                    tmp = req / leg[i] * leg[i]; // lay chieu dai gan nhat vs size yeu cau
                    if(tmp > maxsize)
                        maxsize = tmp;
                }
            }
            
            for(i=0;i<leg.size();i++)
            {
                if(leg[i] < req)
                {
                    tmp = 0;
                    while(tmp < req) // lay max nhat co the
                        tmp += leg[i];
                        
                    if(tmp < minsize)
                        minsize = tmp;
                }
                else if(leg[i] < minsize)
                    minsize = leg[i];
            }
            printf("%ld %ld\n",maxsize,minsize);
        }
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
