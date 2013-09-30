/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10025.inp"
#define fo "10025.out"
/**/
using namespace std;
/**/
long long n;
/**/
bool kiemtra(long long value)
{
    long long temp,gt;
    if(value % 2 == 0)
    {
        temp = value / 2;
        gt = value + 1;
        gt = gt * temp;
    }
    else
    {
        temp = value / 2;
        gt = value + 1;
        gt = gt * temp;
        gt += (value + 1) / 2;
    }
    if(gt >= n && (gt - n) % 2 == 0)
        return true;
    return false;
}
/**/
void input()
{
    long long i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lld",&n);
        if(n < 0)
            n *= -1;
        i = 1;
        while(true)
        {
            if(kiemtra(i))
                break;
            i++;
        }
        printf("%lld\n",i);
        if(ntest != 0)
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
