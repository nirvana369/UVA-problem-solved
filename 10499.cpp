/*
                                                            Hoang Linh
                                                    
                                            Problem: THE LAND OF JUSTICE - 10499 (10499.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10499.inp"
#define fo "10499.out"
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
        if(n == 1)
            printf("0%%\n");
        else
        {
            n = n * 25;
            printf("%lld%%\n",n);
        }
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
