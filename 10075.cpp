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

#define fi "10075.inp"
#define fo "10075.out"
#define maxgt 1000000000
#define earth 6378
/**/
using namespace std;
/**/
struct toado{
                double x,y;    
            };
toado p[110];
double a[110][110];
map <string, int > mmap;
int n;
double pi;
/**/
double kc(toado i,toado j)
{
    return earth * acos(cos(pi * i.x) * cos(pi * j.x) * cos(pi * j.y - pi * i.y) + sin(pi * i.x) * sin(pi * j.x));
}
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j] = maxgt;
}
/**/
void solve()
{
    int i,j,k;
    
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
}
/**/
void input()
{
    int id1,id2;
    int m,q;
    int i,id;
    char s1[1000],s2[1000];
    
    pi = acos(-1)/180.0;
    id = 0;
    while(scanf("%d %d %d",&n,&m,&q) == 3)
    {
        if(!n && !m && !q)
            break;
        mmap.clear();
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s %lf %lf",&s1,&p[i].x,&p[i].y);
            mmap[s1] = i;
        }
            
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&s1,&s2);
            id1 = mmap[s1];
            id2 = mmap[s2];
            a[id1][id2] = int(kc(p[id1],p[id2])+0.5);
        }
        solve();
        if(id)
            printf("\n");
        printf("Case #%d\n",++id);
        for(i=0;i<q;i++)
        {
            scanf("%s %s",&s1,&s2);
            id1 = mmap[s1];
            id2 = mmap[s2];
            if(a[id1][id2] != maxgt)
                printf("%0.lf km\n",a[id1][id2]);
            else
                printf("no route exists\n");
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
