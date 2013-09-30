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

#define fi "11093.inp"
#define fo "11093.out"
/**/
using namespace std;
/**/
long long g[100100],need[100100];
long n;
/**/
void input()
{
    long i;
    long long fuel;
    long vt;
    int ntest,id;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        if(n == 5)
        {
            n = 5;
        }
        for(i=0;i<n;i++)
            scanf("%lld",&g[i]);
        fuel = 0;
        vt = -1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&need[i]);
            fuel += g[i] - need[i];
            if(fuel >= 0)
            {
                if(vt == -1)
                    vt = i+1;
            }
            else
                vt = -1;
        }
        
        if(fuel - g[0] < 0)
            vt = -1;
        else
        {
            for(i=vt-1;i>=0;i--)
                if(g[i] - need[i] < 0)
                    break;
                else
                    vt = i+1;
        }
        
        if(vt < 0)
            printf("Case %d: Not possible\n",id++);
        else
            printf("Case %d: Possible from station %ld\n",id++,vt);
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
