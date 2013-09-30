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

#define fi "12210.inp"
#define fo "12210.out"
/**/
using namespace std;
/**/
int ba[10010],sp[10010];
int b,s;
/**/
int ttd(int value)
{
    if(value < 0)
        return -value;
    return value;
}
/**/
void input()
{
    int i,j;
    int maxgt,id;
    id = 1;
    while(true)
    {
        maxgt = 100;
        scanf("%d %d",&b,&s);
        if(!b && !s)
            break;
        for(i=0;i<b;i++)
        {
            scanf("%d",&ba[i]);
            if(maxgt > ba[i])
                maxgt = ba[i];
        }
        for(i=0;i<s;i++)
            scanf("%d",&sp[i]);

        printf("Case %d: ",id);
        if(b - s > 0)
            printf("%d %d\n",b-s,maxgt);
        else
            printf("0\n");
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
