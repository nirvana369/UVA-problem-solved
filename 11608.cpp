/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11608.inp"
#define fo "11608.out"
/**/
using namespace std;
/**/
int a[13],b[13];
int tong;
/**/
void input()
{
    int i,id;
    id = 1;
    while(true)
    {
        scanf("%d",&tong);
        if(tong < 0)
            break;
        printf("Case %d:\n",id);
        for(i=0;i<12;i++)
            scanf("%d",&a[i]);
        for(i=0;i<12;i++)
            scanf("%d",&b[i]);        
        for(i=0;i<12;i++)
        {
            if(tong >= b[i])
            {
                tong -= b[i];
                printf("No problem! :D\n");
            }
            else
                printf("No problem. :(\n");
            tong += a[i];
        }
        id++;
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
