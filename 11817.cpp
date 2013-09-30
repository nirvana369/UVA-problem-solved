/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11817.inp"
#define fo "11817.out"
#define earth 6371009
/**/
using namespace std;
/**/
struct toado{
                double lat,lon;
            };
toado p[2];
double pi;
/**/
double goc(toado i,toado j)
{
    return acos(cos(pi * i.lat) * cos(pi * j.lat) * cos(pi * j.lon - pi * i.lon) + sin(pi * i.lat) * sin(pi * j.lat));
}
void input()
{
    int i;
    double tmp,len2,len1;
    int ntest;
    scanf("%d",&ntest);
    
    pi = acos(-1)/180;
    
    while(ntest--)
    {
        for(i=0;i<2;i++)
            scanf("%lf %lf",&p[i].lat,&p[i].lon);
        tmp = goc(p[0],p[1]);
        len1 = earth * tmp;
        len2 = earth * sqrt(2 - 2 * cos(tmp));
        printf("%.lf\n",len1-len2);
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
