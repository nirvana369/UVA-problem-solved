/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "11683.inp"
#define fo "11683.out"
/**/
using namespace std;
/**/
/**/
void input()
{
    int h,w;
    int i;
    int a,b;
    int dif;
    
    while(scanf("%d",&h) && h)
    {
        scanf("%d %d",&w,&a);
        dif = 0;
        for(i=1;i<w;i++)
        {
            scanf("%d",&b);
            if(b >= a)
            {
                dif += b - a;
                //swap
                b ^= a;
                a ^= b;
                b ^= a;
                i--;
                w--;
            }
            else
            {
                // swap
                b ^= a;
                a ^= b;
                b ^= a;

                i--;
                w--;
            }
        }
        dif += h - a;
        printf("%d\n",dif);
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
