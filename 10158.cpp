/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10158.inp"
#define fo "10158.out"
/**/
using namespace std;
/**/
int a[30000];
int n;
/**/
void khoitao()
{
    int i;
    for(i=0;i<=n+n;i++)
        a[i] = i;
}
/**/
int fpre(int x)
{
    while(x != a[x])
        x = a[x];
    return x;
}
/**/
void input()
{
    int x,y,rls;
    int fx,fy,ex,ey;
    
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        while(scanf("%d %d %d",&rls,&x,&y) && (rls || x || y))
        {
            if(rls == 1)
            {
                fx = fpre(x);
                fy = fpre(y);
                ex = fpre(x+n);
                ey = fpre(y+n);
                if(fx == ey || fy == ex)
                    printf("-1\n");
                else
                {
                    a[fy] = fx;    
                    a[ey] = ex;
                }
            }
            else if(rls == 2)
            {
                fx = fpre(x);
                fy = fpre(y);
                ex = fpre(x+n);
                ey = fpre(y+n);
                if(fx == fy)
                    printf("-1\n");
                else
                {
                    a[ey] = fx;
                    a[ex] = fy;
                }
            }
            else if(rls == 3)
            {
                fx = fpre(x);
                fy = fpre(y);
                if(fx == fy)
                    printf("1\n");
                else
                    printf("0\n");
            }
            else
            {
                fx = fpre(x);
                fy = fpre(y);
                ex = fpre(x+n);
                ey = fpre(y+n);
                if(fy == ex || fx == ey)
                    printf("1\n");
                else
                    printf("0\n");
            }
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
