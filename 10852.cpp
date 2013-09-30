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

#define fi "10852.inp"
#define fo "10852.out"
#define maxval 10000
/**/
using namespace std;
/**/
int d[maxval+10],nt[maxval];
int dnt;
/**/
void _init()
{
    int i,temp,j;
    
    for(i=0;i<=maxval;i++)
        d[i] = 0;
    d[0] = d[1] = 1;
    temp = (int)sqrt(maxval);
    for(i=2;i<=maxval;i++)
        if(!d[i])
        {
            nt[dnt++] = i;
            if(i <= temp)
                for(j=i*i;j<=maxval;j+=i)
                    d[j] = 1;
        }
    
}
/**/
void input()
{
    int i;
    int ntest;
    int n;
    _init();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<dnt;i++)
            if(nt[i] <= n && nt[i] * 2 > n)
                break;
        printf("%d\n",nt[i]);
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
