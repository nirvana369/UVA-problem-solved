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
#include <vector>

#define fi "11679.inp"
#define fo "11679.out"
/**/
using namespace std;
/**/
int n,m;
long b[30];
/**/
void input()
{
    int i;
    int x,y;
    long val;
    bool possible;
        
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        for(i=1;i<=n;i++)
            scanf("%ld",&b[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %ld",&x,&y,&val);
            b[x] -= val;
            b[y] += val;
        }
        possible = true;
        for(i=1;i<=n;i++)
            if(b[i] < 0)
            {
                possible = false;
                break;
            }
        if(possible)
            printf("S\n");
        else
            printf("N\n");
            
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
