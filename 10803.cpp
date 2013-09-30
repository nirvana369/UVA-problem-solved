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

#define fi "10803.inp"
#define fo "10803.out"
#define maxgt 1e+8
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
double a[110][110];
toado p[110];
int n;
/**/
double gmin(double val1,double val2)
{
    return (val1 < val2) ? val1 : val2;
}
/**/
void solve()
{
    int i,j,k;
    double kq;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                a[j][k] = gmin(a[j][k],a[j][i] + a[i][k]);
    
    kq = 0;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(kq < a[i][j])
                kq = a[i][j];
    if(kq == maxgt)
        printf("Send Kurdy\n");
    else
        printf("%0.4lf\n",kq);
    printf("\n");
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    long val;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
            for(j=i-1;j>=0;j--)
            {
                val = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
                if(val <= 100)
                    a[i][j] = a[j][i] = sqrt(val);
                else
                    a[i][j] = a[j][i]= maxgt;
            }
            a[i][i] = maxgt;
        }
        printf("Case #%d:\n",id++);
        solve();
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
