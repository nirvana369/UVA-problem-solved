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

#define fi "10167.inp"
#define fo "10167.out"
/**/
using namespace std;
/**/
struct cake{
                int x,y;
            };
cake cherry[200];
int n;
/**/
bool kiemtra(int a,int b)
{
    int i;
    int phai,trai;
    phai = 0;
    trai = 0;
    for(i=0;i<n*2;i++)
        if(a * cherry[i].x + b * cherry[i].y > 0)
            phai++;
        else if(a * cherry[i].x + b * cherry[i].y < 0)
            trai++;
        else
            return false;
    if(phai == trai && phai == n)
        return true;
    return false;
}
/**/
void solve()
{
    int i,j;
    int a,b,c;
    for(i=0;i<=500;i++)
        for(j=-500;j<=500;j++)
        {
            if(kiemtra(i,j))
            {
                printf("%d %d\n",i,j);
                return;
            }
        }
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
        for(i=0;i<2*n;i++)
            scanf("%d %d",&cherry[i].x,&cherry[i].y);
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
