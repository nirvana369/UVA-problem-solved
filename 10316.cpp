/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10316.inp"
#define fo "10316.out"
#define earth 6378
/**/
using namespace std;
/**/
struct toado{
                double lat,lon;
            };
int n;
double pi;
toado p[1010];
double val[1010][1010];
/**/
double kc(toado i,toado j)
{
    return earth * acos(cos(pi * i.lat) * cos(pi * j.lat) * cos(pi * j.lon - pi * i.lon) + sin(pi * i.lat) * sin(pi * j.lat));
}
/**/
double rmax(double a,double b)
{
    return (a > b) ? a : b;
}
/**/
void input()
{
    int i,j;
    double kq,tmp;
    toado pos;
    pi = acos(-1)/180.0;
    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&p[i].lat,&p[i].lon);
            for(j=i-1;j>=0;j--)
                val[i][j] = val[j][i] = kc(p[i],p[j]);
        }
        kq = 1000000000;
        pos.lat = pos.lon = 0;
        for(i=0;i<n;i++)
        {
            tmp = 0;
            for(j=0;j<n;j++)
                if(i != j)
                    tmp = rmax(tmp,val[i][j]);
            if(tmp < kq || fabs(tmp - kq) < 1e-5)
            {
                kq = tmp;
                pos = p[i];
            }
        }
        printf("%0.2lf %0.2lf\n",pos.lat,pos.lon);
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
