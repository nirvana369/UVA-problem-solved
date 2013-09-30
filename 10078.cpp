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

#define fi "10078.inp"
#define fo "10078.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
int d[60];
toado p[60];
int n,s;
/**/
bool kiemtra(int i,int j)
{
    int k;
    int a,b,c;
    a = p[i].y - p[j].y;
    b = p[j].x - p[i].x;
    c = -(a * p[i].x + b * p[i].y);
    for(k=0;k<n;k++)
        if(a * p[k].x + b * p[k].y + c > 0)
            return false;
    return true;
}
/**/
void solve()
{
    int i;
    int dau,dem;
    dau = s;
    dem = 0;
    while(true)
    {
        for(i=0;i<n;i++)
            if(d[i] == 0 && i != dau && kiemtra(dau,i))
            {
                dau = i;
                dem++;
                break;
            }
        if(dau == s)
            break;
    }
    if(dem != n)    
        printf("Yes\n");
    else
        printf("No\n");
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        s = 0;
        for(i=0;i<n;i++)
        {
            d[i] = 0;
            scanf("%d %d",&p[i].x,&p[i].y);
            if(i)
            {
                if(p[i].x < p[s].x)
                    s = i;
                else if(p[i].x == p[s].x)
                    if(p[i].y < p[s].y)
                        s = i;
            }
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
