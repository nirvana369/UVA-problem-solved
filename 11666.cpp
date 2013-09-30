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

#define fi "11666.inp"
#define fo "11666.out"
/**/
using namespace std;
/**/
void input()
{
    int l;
    long n;
    double ans,e;
    e = 2.718281828459045;
    
    while(scanf("%ld",&n))    
    {
        if(!n)
            break;
        l = 0;
        ans = 1.0 - (double)n / pow(e,l);
        while(!(fabs(ans) < 1.0))
        {
            l++;
            ans = 1.0 - (double)n / pow(e,l);
        }
        printf("%d %0.8lf\n",l,ans);
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
