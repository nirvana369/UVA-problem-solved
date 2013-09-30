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

#define fi "10911.inp"
#define fo "10911.out"
#define maxval 1000000000
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado p[20];
double a[20][20],dist[10][20][20];
bool d[20];
int n,m;
double val;
/**/
double kc(int i,int j)
{
    return sqrt((p[i].x-p[j].x) * (p[i].x-p[j].x) + (p[i].y-p[j].y) * (p[i].y-p[j].y));
}
/**/
void khoitao()
{
    int i,j,k;
    
    for(k=0;k<n;k++)
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
                dist[k][i][j] = maxval;
                
    val = maxval;
}
/**/
void solve(int bac,double gt)
{
    int i,j;
    
    if(bac == n-1)
    {
        if(gt < val)
            val = gt;
        return;
    }
    
    for(i=1;i<=m;i++)
        if(d[i])
        {
            d[i] = false;
            
            for(j=i+1;j<=m;j++)
                if(d[j])
                    if(gt + a[i][j] <= dist[bac+1][i][j])
                    {
                        dist[bac+1][i][j] = gt + a[i][j];
                        
                        d[j] = false;
                        
                        solve(bac+1,dist[bac+1][i][j]);
                        
                        d[j] = true;
                    }
            d[i] = true;
        }
}
/**/
void input()
{
    int i,j,id;
    char s[1000];
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        m = n * 2;
        for(i=1;i<=m;i++)
        {
            scanf("%s %d %d",&s,&p[i].x,&p[i].y);
            for(j=i-1;j>=1;j--)
                a[i][j] = a[j][i] = kc(i,j);
            d[i] = true;
        }
        khoitao();

        for(i=1;i<=m;i++)
        {
            for(j=i+1;j<=m;j++)
            {
                if(i != j)
                {
                    d[i] = d[j] = false;
                    solve(0,a[i][j]);
                    d[i] = d[j] = true;
                }
            }
        }
        printf("Case %d: %0.2lf\n",id++,val);
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
