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
#include <vector>

#define fi "535.inp"
#define fo "535.out"
#define earth 6378
/**/
using namespace std;
/**/
struct toado{
                double lat,lon;
            };
toado p[110];
int n;
double a[110][110];
double pi;
map<string, int> mmap;
/**/
double kc(toado i,toado j)
{
    return earth * acos(cos(pi * i.lat) * cos(pi * j.lat) * cos(pi * j.lon - pi * i.lon) + sin(pi * i.lat) * sin(pi * j.lat));
}
/**/
void solve()
{
    int i,j,k;
    
    for(i=1;i<n;i++)
        for(j=i+1;j<n;j++)
            a[i][j] = a[j][i] = kc(p[i],p[j]);
    
    for(k=1;k<n;k++)
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    
}
/**/
void input()
{
    int id1,id2;
    char s1[100],s2[100];
    n = 1;
    pi = acos(-1) / 180.0;
    mmap.clear();
    while(true)
    {
        scanf("%s",&s1);
        if(strcmp(s1,"#") == 0)
            break;
        mmap[s1] = n;
        scanf("%lf %lf",&p[n].lat,&p[n].lon);
        n++;
    }
    solve();
    while(true)
    {
        scanf("%s %s",&s1,&s2);
        if(strcmp(s1,"#") == 0 && strcmp(s2,"#") == 0)
            break;
        id1 = mmap[s1];
        id2 = mmap[s2];
        printf("%s - %s\n",s1,s2);
        if(!id1 || !id2)
            printf("Unknown\n");
        else
            printf("%.lf km\n",a[id1][id2]);
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
