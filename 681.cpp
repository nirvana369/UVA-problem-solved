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

#define fi "681.inp"
#define fo "681.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado p[600];
int kq[600],d[600];
int n,xp;
/**/
bool kiemtra(int g1,int g2)
{
    int a,b,c;
    int i;
    int demam;
    a = p[g1].y - p[g2].y;
    b = p[g2].x - p[g1].x;
    c = -(a * p[g1].x + b * p[g1].y);
    
    demam = 0;
    for(i=0;i<n;i++)
        if(i != g1 && i!= g2)
        {
            if(a * p[i].x + b * p[i].y + c < 0)
                return false;
            if(a * p[i].x + b * p[i].y + c == 0)
            {
                if((p[i].x - p[g1].x) * (p[i].x - p[g2].x) > 0)
                    return false;
                if((p[i].y - p[g1].y) * (p[i].y - p[g2].y) > 0)
                    return false;
            }
        }
    return true;
}
/**/
bool khac(int i,int j)
{
    if(p[i].x != p[j].x || p[i].y != p[j].y)
        return true;
    return false;
}
/**/
bool giong(int i,int j)
{
    if(p[i].x == p[j].x && p[i].y == p[j].y)
        return true;
    return false;
}
/**/
void solve()
{
    int i,j;
    int tg,dem;

    tg = xp;
    kq[0] = xp;
    dem = 0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            if(giong(i,j))
                d[j] = 1;
    }
    dem = 1;
    while(true)
    {
        for(i=0;i<n;i++)
            if(i != tg && d[i] == 0 && kiemtra(tg,i))
            {
                kq[dem] = i;
                dem++;
                d[i] = 1;
                tg = i;
                break;
            }
        if(p[xp].x == p[tg].x && p[xp].y == p[tg].y)
            break;
    }
    printf("%d\n",dem);
    for(i=0;i<dem;i++)
        printf("%d %d\n",p[kq[i]].x,p[kq[i]].y);
}
/**/
void input()
{
    int i;
    int ntest,neg;
    scanf("%d",&ntest);
    printf("%d\n",ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        xp = 0;
        for(i=0;i<n;i++)
        {
            d[i] = 0;
            scanf("%d %d",&p[i].x,&p[i].y);
            if(p[i].y < p[xp].y)
                xp = i;
            else if(p[i].y == p[xp].y)
                if(p[i].x < p[xp].x)
                    xp = i;
        }
        scanf("%d",&neg);
        solve();
        if(ntest)
            printf("-1\n");
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
