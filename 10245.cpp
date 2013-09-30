/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10245.inp"
#define fo "10245.out"
/**/
using namespace std;
/**/
struct toado{
                double x,y;
            };
toado td[10010];
int n;
/**/
bool sosanh(int i,int j)
{
    if(td[i].x > td[j].x)
        return true;
    else if(td[i].x == td[j].x)
    {
        if(td[i].y > td[j].y)
            return true;
        return false;
    }
    return false;
}
/**/
double kc(double ax,double ay,double bx,double by)
{
    return sqrt((ax-bx) * (ax-bx) + (ay-by) * (ay-by));
}
/**/
void stree(int i,int j)
{
    toado temp;
    temp = td[i];
    td[i] = td[j];
    td[j] = temp;
}
/**/
void utree(int i)
{
    if(i == 1)
        return;
    if(sosanh(i,i/2))
    {
        stree(i,i/2);
        utree(i/2);
    }
}
/**/
void mtree(int i)
{
    if(i*2+1 <= n)
    {
        if(sosanh(i*2+1,i*2))
        {
            if(sosanh(i*2+1,i))
            {
                stree(i*2+1,i);
                mtree(i*2+1);
            }
        }
        else if(sosanh(i*2,i))
        {
            stree(i*2,i);
            mtree(i*2);
        }
    }
    else if(i*2 <= n)
    {
        if(sosanh(i*2,i))
        {
            stree(i*2,i);
            mtree(i*2);
        }
    }
}
/**/
void solve()
{
    int i,j;
    int temp;
    double tg,distance;
    
    temp = n;
    while(n)
    {
        stree(1,n);
        n--;
        mtree(1);
    }
    
    n = temp;
    distance = 10000;
    for(i=2;i<=n;i++)
    {
        if(i-2 >= 1)
            temp = i-100;
        else
            temp = 1;
        for(j=i-1;j>=temp;j--)
        {
            tg = kc(td[i].x,td[i].y,td[j].x,td[j].y);
            if(tg < distance)
                distance = tg;
        }
    }
    
    if(distance < 10000)
        printf("%0.4lf\n",distance);
    else
        printf("INFINITY\n");
}
/**/
void input()
{
    int i,j;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf",&td[i].x,&td[i].y);
            utree(i);
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
