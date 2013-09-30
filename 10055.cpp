/*
                                                Hoang Linh

                            Problem: HASHMAT THE BRAVE WARRIOR - 10055 (10055.*)                                    
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10055.inp"
#define fo "10055.out"
/**/
using namespace std;
/**/
long long absl(long long value)
{
    if(value < 0)
        return value * (-1);
    return value;
}
/**/
void input()
{
    long long a,b,kq;
    while(scanf("%lld %lld",&a,&b) == 2)
    {
        kq = absl(a-b);
        printf("%lld\n",kq);
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
