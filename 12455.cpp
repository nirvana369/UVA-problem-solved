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

#define fi "12455.inp"
#define fo "12455.out"
/**/
using namespace std;
/**/
int bar[25];
int n,p;
bool y;
/**/
void sapxep()
{
    int i,j;
    int temp;
    
    for(i=0;i<p-1;i++)
        for(j=i+1;j<p;j++)
            if(bar[i] < bar[j])
            {
                temp = bar[i];
                bar[i] = bar[j];
                bar[j] = temp;
            }
}
/**/
void dq(int id,int len)
{
    int i;
    if(!len)
    {
        y = true;
        return;
    }
    for(i=id;i<p;i++)
    {
        if(len - bar[i] >= 0)
            dq(i+1,len-bar[i]);
        if(y)
            return;
    }
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&p);
        for(i=0;i<p;i++)
            scanf("%d",&bar[i]);
        y = false;
        if(!n)
            y = true;
        else
        {
            sapxep();
            dq(0,n);
        }
        if(y)
            printf("YES\n");
        else
            printf("NO\n");
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
