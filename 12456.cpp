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

#define fi "12456.inp"
#define fo "12456.out"
/**/
using namespace std;
/**/
int a[10000];
/**/
void input()
{
    int n,i;
    long prd;
    int mingt;
    
    while(scanf("%d",&n))
    {
        if(!n)   
            break;
        prd = mingt = 1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            prd *= a[i];
        }
        n--;
        i = 0;
        while(i <= n)
        {
            mingt *= a[i] > a[n] ? a[n] : a[i];
            i++;
            n--;
        }
        printf("%d\n",prd-mingt);
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
