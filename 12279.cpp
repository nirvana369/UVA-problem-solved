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

#define fi "12279.inp"
#define fo "12279.out"
/**/
using namespace std;
/**/
void input()
{
    int i,id;
    int d1,d2,n;
    int tg;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        d1 = d2 = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&tg);
            if(tg != 0)
                d1++;
            else
                d2++;
        }
        printf("Case %d: %d\n",id++,d1-d2);
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
