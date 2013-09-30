/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "866.inp"
#define fo "866.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado p[500][2];
int n,insec;
/**/
bool kiemtra(int i1,int i2)
{
    double x,y;
    int a1,b1,c1,a2,b2,c2,d,dx,dy;
    int dem;
    
    a1 = p[i1][0].y - p[i1][1].y;
    b1 = p[i1][1].x - p[i1][0].x;
    c1 = -(p[i1][0].x * a1 + b1 * p[i1][0].y);
    
    a2 = p[i2][0].y - p[i2][1].y;
    b2 = p[i2][1].x - p[i2][0].x;
    c2 = -(p[i2][0].x * a2 + b2 * p[i2][0].y);
    
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = c1 * a2 - c2 * a1;
    
    if(d != 0)
    {
        x = (double)dx / d;
        y = (double)dy / d;
        dem = 0;
        
        if((x - (double)p[i1][0].x) * (x - (double)p[i1][1].x) <= 0 && (y - (double)p[i1][0].y) * (y - (double)p[i1][1].y) <= 0)
            dem++;
            
        if((x - (double)p[i2][0].x) * (x - (double)p[i2][1].x) <= 0 && (y - (double)p[i2][0].y) * (y - (double)p[i2][1].y) <= 0)
            dem++;
            
        if(dem == 2)
            return true;
            
        return false;
    }
    return false;
}
/**/
void solve()
{
    int i,j;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(j != i && kiemtra(i,j))
                insec++;
    printf("%d\n",insec);
}
/**/
void input()
{
    int i,j;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        insec = n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<2;j++)
                scanf("%d %d",&p[i][j].x,&p[i][j].y);
        }
        solve();
        if(ntest)
            printf("\n");
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
