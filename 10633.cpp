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

#define fi "10633.inp"
#define fo "10633.out"
/**/
using namespace std;
/**/
void input()
{
    unsigned long long i;
    unsigned long long n,m,maxm;
    bool space;
    while(scanf("%llu",&n))
    {
        if(!n)
            break;
        space = false;
        maxm = n*10/9;          // m - m / 10 = n
        for(i=maxm-10;i<=maxm+10;i++) // search in range
            if(i-(i/10) == n)
            {
                if(space)
                    printf(" ");
                else
                    space = true;
                printf("%llu",i);
            }
        printf("\n");
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
