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

#define fi "10714.inp"
#define fo "10714.out"
/**/
using namespace std;
/**/
void input()
{
    long i;
    int ntest;
    long minl,maxl;
    long n,val,len;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&len,&n);
        maxl = minl = 0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&val);
            val = val < (len-val) ? val : (len-val);
            if(val > minl)
                minl = val;
            if(len-val > maxl)
                maxl = len-val;
        }
        printf("%ld %ld\n",minl,maxl);
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
