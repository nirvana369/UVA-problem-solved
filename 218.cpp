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

#define fi "218.inp"
#define fo "218.out"
/**/
using namespace std;
/**/
struct toado{
                float x,y;
            };
toado p[10000];
int n,xp;
/**/
bool kiemtra(int g1,int g2)
{
    float a,b,c;
    int i;
    int demam;
    a = p[g1].y - p[g2].y;
    b = p[g2].x - p[g1].x;
    c = -(a * p[g1].x + b * p[g1].y);
    
    demam = 0;
    for(i=0;i<n;i++)
        if(i != g1 && i!= g2)
            if(a * p[i].x + b * p[i].y + c <= 0)
                demam++;
    if(demam == n-2)
        return true;
    return false;
}
/**/
double kc(int i,int j)
{
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
/**/
void solve()
{
    int i;
    int tg;
    double tong;

    tg = xp;
    printf("(%0.1f,%0.1f)",p[xp].x,p[xp].y);
    tong = 0;
    while(true)
    {
        for(i=0;i<n;i++)
            if(i != tg && kiemtra(tg,i))
            {
                printf("-(%0.1f,%0.1f)",p[i].x,p[i].y);
                tong = tong + kc(tg,i);
                tg = i;
                break;
            }
        if(tg == xp)
            break;
    }
    printf("\nPerimeter length = %0.2lf\n",tong);
}
/**/
void input()
{
    int i;
    int id;
    id = 0;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        if(id)
            printf("\n");
        xp = 0;
        for(i=0;i<n;i++)
        {
            scanf("%f %f",&p[i].x,&p[i].y);
            if(p[i].x <= p[xp].x && p[i].y <= p[xp].y)
                xp = i;
        }
        printf("Region #%d:\n",++id);
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
