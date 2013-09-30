/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "104.inp"
#define fo "104.out"
/**/
using namespace std;
/**/
double a[25][25][25];
int trc[25][25][25];
int n;
/**/
void output(int x,int step)
{
    int i,j;
    int kq[100];
    
    j = x;
    kq[i++] = x;
    while(step != 1)
    {
        kq[i++] = trc[x][j][step];
        j = trc[x][j][step];
        step--;
    }
    kq[i] = trc[x][j][step];
    for(j=i;j>=0;j--)
    {
        printf("%d",kq[j]+1);
        if(j)
            printf(" ");
    }
    printf("\n");
}
/**/
void solve()
{
    int i,j,k,s;
    double tmp;
    
    for(s=2;s<=n;s++)
        for(k=0;k<n;k++)
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                {
                    tmp = a[i][k][s-1] * a[k][j][1];
                    if(tmp > a[i][j][s])
                    {
                        a[i][j][s] = tmp;
                        trc[i][j][s] = k;
                    }
                }
    
    for(s=2;s<=n;s++)
        for(i=0;i<n;i++)
            if(a[i][i][s] > 1.01)
            {
                output(i,s);
                return;
            }
            
    printf("no arbitrage sequence exists\n");
}
/**/
void khoitao()
{
    int i,j,k;
    
    for(k=2;k<=n;k++)   
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                a[i][j][k] = 0;
                trc[i][j][k] = i;
            }
}
/**/
void input()
{
    int i,j;
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                trc[i][j][1] = i;
                if(i == j)
                    a[i][j][1] = 1;
                else
                    scanf("%lf",&a[i][j][1]);
            }
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
