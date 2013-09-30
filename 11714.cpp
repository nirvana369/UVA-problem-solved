/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11714.inp"
#define fo "11714.out"
/**/
using namespace std;
/**/
void input()
{
    long long n;
    while(true)
    {
        n = -1;
        scanf("%lld",&n);
        if(n == -1)
            break;
        printf("%lld\n",n-1 + (long long)log2(n-1));
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
