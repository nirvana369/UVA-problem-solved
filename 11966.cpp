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

#define fi "11966.inp"
#define fo "11966.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
toado p[1010];
int d[1010],a[1010][1010],q[1010];
int n;
double dist;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            a[i][j] = a[j][i] = 0;
        d[i] = 0;
    }
}
/**/
double kc(toado i,toado j)
{
    return sqrt((i.x-j.x) * (i.x-j.x) + (i.y-j.y) * (i.y-j.y));
}
/**/
void loang(int xp)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[cuoi] = xp;
    d[xp] = 1;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<n;i++)
            if(a[q[dau]][i] && !d[i])
            {
                cuoi++;
                q[cuoi] = i;
                d[i] = 1;
            }
    }
}
/**/
void solve(int id)
{
    int i;
    int land;
    
    land = 0;
    for(i=0;i<n;i++)
        if(!d[i])
        {
            land++;
            loang(i);
        }
        
    printf("Case %d: %d\n",id,land);
}
/**/
void input()
{
    int i,j;
    int ntest,id; 
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %lf",&n,&dist);
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
            for(j=0;j<i;j++)
                if(kc(p[i],p[j]) <= dist)
                    a[i][j] = a[j][i] = 1;
        }
        solve(id++);
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
