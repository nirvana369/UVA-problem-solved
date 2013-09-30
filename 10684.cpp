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

#define fi "10684.inp"
#define fo "10684.out"
/**/
using namespace std;
/**/
int a[10100],kq[10100];
int n;
int win;
/**/
void input()
{
    int i;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        win = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i)
            {
                if(kq[i-1] + a[i] > a[i])
                    kq[i] = kq[i-1] + a[i];
                else
                    kq[i] = a[i];
                    
                if(kq[i] > win)
                    win = kq[i];
            }
            else
            {
                kq[i] = a[i];
                if(kq[i] > win)
                    win = kq[i];
            }
        }
        if(win)
            printf("The maximum winning streak is %d.\n",win);
        else
            printf("Losing streak.\n");
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
