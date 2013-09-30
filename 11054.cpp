/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11054.inp"
#define fo "11054.out"
/**/
using namespace std;
/**/
long long _abs(long long gt)
{
    if(gt < 0)
        return -gt;
    return gt;
}
/**/
void input()
{
    long n;
    int val;
    long long sum,carry;
    
    while(scanf("%ld",&n) && n)
    {
        n--;
        scanf("%d",&val);
        sum = val;
        carry = _abs(val);
        while(n--)
        {
            scanf("%d",&val);
            sum += val;
            carry += _abs(sum);
        }
        printf("%lld\n",carry);
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
