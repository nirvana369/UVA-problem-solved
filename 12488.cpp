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

#define fi "12488.inp"
#define fo "12488.out"
/**/
using namespace std;
/**/
int n;
int a[30];
/**/
int swapr(int vt,int val)
{
    int i,j;
    int tg,dem;
    dem = 0;
    for(i=0;i<n;i++)
        if(a[i] == val)
        {
            for(j=i;j>vt;j--)
            {
                tg = a[j];
                a[j] = a[j-1];
                a[j-1] = tg;
                dem++;
            }
            break;
        }
    return dem;
}
/**/
void input()
{
    int i,j;
    int gt,dem;
    
    while(scanf("%d",&n) == 1)
    {
        dem = 0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(i=0;i<n;i++)
        {
            scanf("%d",&gt);
            if(gt != a[i])
                dem += swapr(i,gt);
        }
        printf("%d\n",dem);
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
