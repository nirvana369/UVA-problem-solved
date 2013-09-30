/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11450.inp"
#define fo "11450.out"
/**/
using namespace std;
/**/
int a[25][25],sl[25];
int m,mgold,c;
bool done;
/**/
void dq(int gold,int id)
{
    int i;
    if(id == c)
    {
        done = true;
        if(gold < mgold)
            mgold = gold;
        return;
    }
    for(i=0;i<sl[id];i++)
        if(gold - a[id][i] >= 0)
        {
            dq(gold-a[id][i],id+1);
            if(done && !mgold)
                return;
        }
}
/**/
void input()
{
    int i,j;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&m,&c);
        for(i=0;i<c;i++)
        {
            scanf("%d",&sl[i]);
            for(j=0;j<sl[i];j++)
                scanf("%d",&a[i][j]);
        }
        done = false;
        mgold = m;
        dq(m,0);
        if(done)
            printf("%d\n",m-mgold);
        else
            printf("no solution\n");
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
