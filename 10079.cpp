/*
                                                        Hoang Linh
                                                        
                                        Problem: PIZZA CUTTING - 10079 (10079.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10079.inp"
#define fo "10079.out"
/**/
using namespace std;
/**/
void input()
{
    long long n;
    while(true)
    {
        scanf("%lld",&n);
        if(n < 0)
            break;
        n = (n*(n+1))/2 + 1;
        printf("%lld\n",n);
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
