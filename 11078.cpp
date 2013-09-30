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

#define fi "11078.inp"
#define fo "11078.out"
/**/
using namespace std;
/**/
void input()
{
    long i;
    long long danhdau,val;
    long diff,n;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        scanf("%lld",&danhdau);        
        diff = -200000;
        for(i=1;i<n;i++)
        {
            scanf("%lld",&val);
            if(val > danhdau)
                danhdau = val;
            else if(danhdau - val > diff)
                diff = danhdau - val;
        }
        if(diff == -200000)
            printf("-1\n");
        else
            printf("%ld\n",diff);
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
